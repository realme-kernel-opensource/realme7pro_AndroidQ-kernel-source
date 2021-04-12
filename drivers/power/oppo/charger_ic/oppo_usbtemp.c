#include <linux/ktime.h>
#include <linux/delay.h>
#include <linux/module.h>
#include <linux/kthread.h>
#include <linux/iio/consumer.h>

#include "../charger_ic/op_charge.h"
#include "../oppo_charger.h"
#include "../oppo_gauge.h"
#include "../oppo_vooc.h"


#ifdef VENDOR_EDIT
//YanGang@BSP.CHG.Basic, 2020/01/16, add for new dischg plan.
#define USB_40C	400
#define USB_50C	500

#ifdef CONFIG_OPPO_CHARGER_MTK
#define VBUS_VOLT_THRESHOLD	3000
#else
#define VBUS_VOLT_THRESHOLD	400
#endif
#define CHARGE_CURRENT_THRESHOLD	-4500

#define USBTEMP_DEFAULT_VOLT_VALUE_MV 1285

#define VBUS_MONITOR_INTERVAL	3000//3s

#define MIN_MONITOR_INTERVAL	50//50ms
#define MAX_MONITOR_INTERVAL	50//50ms
#define RETRY_CNT_DELAY         5 //ms

static int usbtemp_debug = 0;
module_param(usbtemp_debug, int, 0644);
#define OPEN_LOG_BIT BIT(0)
#define TEST_FUNC_BIT BIT(1)
MODULE_PARM_DESC(usbtemp_debug, "debug usbtemp");
#define USB_TEMP_HIGH 0x01
void oppo_set_usb_temp_high(struct oppo_chg_chip *chip)
{
	chip->usb_status |= USB_TEMP_HIGH;
}
void oppo_clear_usb_temp_high(struct oppo_chg_chip *chip)
{
	chip->usb_status = chip->usb_status & (~USB_TEMP_HIGH);
}

void oppo_get_usbtemp_volt(struct oppo_chg_chip *chip)
{
	int rc, i, temp_volt = 0, usbtemp_volt = 0;
	struct smb_charger *chg = NULL;

    if (!chip) {
		chg_err("smb5_chg not ready!\n");
		return ;
	}
	chg = &chip->pmic_spmi.smb5_chip->chg;

	if (IS_ERR_OR_NULL(chg->iio.usbtemp_v_chan)) {
		chg_err("[OPPO_CHG][%s]: chg->iio.usbtemp_v_chan  is  NULL !\n");
		chip->usbtemp_volt_l = USBTEMP_DEFAULT_VOLT_VALUE_MV;
		goto usbtemp_next;
	}
	for (i = 0; i < 3; i++) {
		mutex_lock(&chg->adc_lock);
		rc = iio_read_channel_processed(chg->iio.usbtemp_v_chan, &temp_volt);
		mutex_unlock(&chg->adc_lock);
		if (rc < 0) {
			chg_err("iio_read_channel_processed  get error\n");
			chip->usbtemp_volt_l = USBTEMP_DEFAULT_VOLT_VALUE_MV;
			goto usbtemp_next;
		}

		temp_volt = temp_volt / 1000;
		usbtemp_volt += temp_volt;
		if(usbtemp_debug & OPEN_LOG_BIT)
			chg_err("temp_volt_l:%d, usbtemp_volt:%d\n",temp_volt, usbtemp_volt);
		msleep(5);
	}
	chip->usbtemp_volt_l = usbtemp_volt / 3;
	if (chip->usbtemp_volt_l > USBTEMP_DEFAULT_VOLT_VALUE_MV) {
		chip->usbtemp_volt_l = USBTEMP_DEFAULT_VOLT_VALUE_MV;
	}

usbtemp_next:
	usbtemp_volt = 0;
	temp_volt = 0;
	if (IS_ERR_OR_NULL(chg->iio.usbtemp_sup_v_chan)) {
		chg_err("chg->iio.usbtemp_sup_v_chan  is  NULL !\n");
		chip->usbtemp_volt_r = USBTEMP_DEFAULT_VOLT_VALUE_MV;
		return;
	}
	for (i = 0; i < 3; i++) {
		mutex_lock(&chg->adc_lock);
		rc = iio_read_channel_processed(chg->iio.usbtemp_sup_v_chan, &temp_volt);
		mutex_unlock(&chg->adc_lock);
		if (rc < 0) {
			chg_err("iio_read_channel_processed  get error\n");
			chip->usbtemp_volt_r = USBTEMP_DEFAULT_VOLT_VALUE_MV;
			return;
		}

		temp_volt = temp_volt / 1000;
		usbtemp_volt += temp_volt;
		if(usbtemp_debug & OPEN_LOG_BIT)
			chg_err("temp_volt_r:%d, usbtemp_volt_r:%d\n",temp_volt, usbtemp_volt);
		msleep(5);
	}
	chip->usbtemp_volt_r = usbtemp_volt / 3;
	if (chip->usbtemp_volt_r > USBTEMP_DEFAULT_VOLT_VALUE_MV) {
		chip->usbtemp_volt_r = USBTEMP_DEFAULT_VOLT_VALUE_MV;
	}

	if(usbtemp_debug & OPEN_LOG_BIT)
		chg_err("usbtemp_volt_l:%d, usbtemp_volt_r:%d\n",chip->usbtemp_volt_l, chip->usbtemp_volt_r);
}

static void get_usb_temp(struct oppo_chg_chip *chip)
{
	int resistance1, resistance2, index = 0;

	resistance1 = voltage_convert_resistance(chip->usbtemp_volt_l, PULL_UP_VOLTAGE_1800MV, PULL_UP_RESISTANCE_51KOHM);
	resistance2 = voltage_convert_resistance(chip->usbtemp_volt_r, PULL_UP_VOLTAGE_1800MV, PULL_UP_RESISTANCE_51KOHM);

	resistance_convert_temperature(resistance1, chip->usb_temp_l, index, ntc_table_100K);
	resistance_convert_temperature(resistance2, chip->usb_temp_r, index, ntc_table_100K);

	if(usbtemp_debug & TEST_FUNC_BIT){
		chip->usb_temp_r = 600;
	}
	if(usbtemp_debug & OPEN_LOG_BIT)
		chg_err("usb_temp_l:%d, usb_temp_r:%d\n",chip->usb_temp_l, chip->usb_temp_r);
}

int oppo_usbtemp_dischg_action(struct oppo_chg_chip *chip)
{
	int rc = 0;
#ifndef CONFIG_OPPO_CHARGER_MTK
	struct smb_charger *chg = NULL;
	chg = &chip->pmic_spmi.smb5_chip->chg;
#endif

#ifndef CONFIG_HIGH_TEMP_VERSION
	oppo_set_usb_temp_high(chip);
	if (oppo_vooc_get_fastchg_started() == true) {
		oppo_chg_set_chargerid_switch_val(0);
		oppo_vooc_switch_mode(NORMAL_CHARGER_MODE);
		oppo_vooc_reset_mcu();
		//msleep(20);//wait for turn-off fastchg MOS
	}
#ifdef CONFIG_OPPO_CHARGER_MTK
	chip->chg_ops->charging_disable();
#endif

	usleep_range(10000,10000);///msleep(10);
	chip->chg_ops->charger_suspend();
	usleep_range(10000,10000);
	chg_err("run_action");
	if(chip->chg_ops->set_typec_sinkonly != NULL){
		chip->chg_ops->set_typec_sinkonly();
	} else {
		chg_err("set_typec_sinkonly is null");
	}
	usleep_range(12000,12000);

#endif//CONFIG_HIGH_TEMP_VERSION

#ifndef CONFIG_OPPO_CHARGER_MTK
	mutex_lock(&chg->pinctrl_mutex);
#endif

#ifdef CONFIG_HIGH_TEMP_VERSION
	chg_err(" CONFIG_HIGH_TEMP_VERSION enable here,do not set vbus down \n");
	rc = pinctrl_select_state(chip->normalchg_gpio.pinctrl, chip->normalchg_gpio.dischg_disable);
#else
	chg_err("set vbus down");
	rc = pinctrl_select_state(chip->normalchg_gpio.pinctrl, chip->normalchg_gpio.dischg_enable);
#endif


#ifndef CONFIG_OPPO_CHARGER_MTK
	mutex_unlock(&chg->pinctrl_mutex);
#endif

	return 0;
}
//needed to be fixed the level value should be placed into irq 
int recovery_usbtemp(void* data)
{
	struct oppo_chg_chip *chip =(struct oppo_chg_chip *) data;
#ifndef CONFIG_OPPO_CHARGER_MTK
	struct smb_charger *chg = NULL;

	chg = &chip->pmic_spmi.smb5_chip->chg;
	chg_err("recovery_start");
	if (!IS_ERR_OR_NULL(chip->normalchg_gpio.dischg_disable)
				&& chip->dischg_flag == true) {
		chip->dischg_flag = false;
		chg_err("dischg disable...[%d]\n", chip->usbtemp_volt);
		oppo_clear_usb_temp_high(chip);
		mutex_lock(&chg->pinctrl_mutex);
		pinctrl_select_state(chip->normalchg_gpio.pinctrl,
		chip->normalchg_gpio.dischg_disable);
		mutex_unlock(&chg->pinctrl_mutex);
		chg_err("gotta success");
	}
#endif

	return 0;
}

int oppo_usbtemp_monitor_common(void *data)
{
	int delay = 0;
	int vbus_volt = 0;
	static int count = 0;
	static int total_count = 0;
	static int last_usb_temp_l = 25;
	static int current_temp_l = 25;
	static int last_usb_temp_r = 25;
	static int current_temp_r = 25;
	int retry_cnt = 3, i = 0;
	int count_r = 1, count_l = 1;
	bool condition1 = false;
	bool condition2 = false;
	struct oppo_chg_chip *chip = (struct oppo_chg_chip *) data;
#ifndef CONFIG_OPPO_CHARGER_MTK
	struct smb_charger *chg = NULL;
	chg = &chip->pmic_spmi.smb5_chip->chg;
#endif
	chg_err("run first!");

	while (!kthread_should_stop()) {
		if(chip->chg_ops->oppo_usbtemp_monitor_condition != NULL){
			wait_event_interruptible(chip->oppo_usbtemp_wq,chip->chg_ops->oppo_usbtemp_monitor_condition());
		} else {
			chg_err("condition pointer is NULL");
			return 0;
		}
		if(chip->dischg_flag == true){
			goto dischg;
		}

		oppo_get_usbtemp_volt(chip);
		get_usb_temp(chip);
		if ((chip->usb_temp_l < USB_50C) && (chip->usb_temp_r < USB_50C)){//get vbus when usbtemp < 50C
			vbus_volt = chip->chg_ops->get_charger_volt();
		} else{
			vbus_volt = 0;
		}

		if ((chip->usb_temp_l < USB_40C) && (chip->usb_temp_r < USB_40C)) {
			delay = MAX_MONITOR_INTERVAL;
			total_count = 10;
		} else {
			delay = MIN_MONITOR_INTERVAL;
			total_count = 30;
		}

		if ((chip->usbtemp_volt_l < USB_50C) && (chip->usbtemp_volt_r < USB_50C) && (vbus_volt < VBUS_VOLT_THRESHOLD))
			delay = VBUS_MONITOR_INTERVAL;
		//condition1  :the temp is higher than 57
		if (((chip->usb_temp_l >= CRITICAL_TEMPERATURE) && (chip->usb_temp_l < VALID_HIGH_TEMPERATURE))
			|| ((chip->usb_temp_r >= CRITICAL_TEMPERATURE) && (chip->usb_temp_r < VALID_HIGH_TEMPERATURE))) {
			chg_err("in loop 1");
			for (i = 1; i < retry_cnt; i++) {
				mdelay(RETRY_CNT_DELAY);
				oppo_get_usbtemp_volt(chip);
				get_usb_temp(chip);
				if (chip->usb_temp_r >= CRITICAL_TEMPERATURE)
					count_r++;
				if (chip->usb_temp_l >= CRITICAL_TEMPERATURE)
					count_l++;
				chg_err("countl : %d",count_l);
			}
			if (count_r >= retry_cnt || count_l >= retry_cnt) {
				if (!IS_ERR_OR_NULL(chip->normalchg_gpio.dischg_enable)) {
					chip->dischg_flag = true;
					condition1 = true;
					chg_err("dischg enable1...[%d, %d]\n", chip->usb_temp_l, chip->usb_temp_r);
				}
			}
			count_r = 1;
			count_l = 1;
			count = 0;
		}
		if(condition1 == true){
			chg_err("jump_to_dischg");
			goto dischg;
		}
		//chg_err("chip->temperature[%d], chip->authenticate[%d], vbus_volt[%d]\n", chip->temperature, chip->authenticate, vbus_volt);
		//condition2  :the temp uprising to fast
		if ((((((chip->usb_temp_l - chip->temperature) > CRITICAL_USBTEMP_ABOVE_BATTEMP_1) || ((chip->usb_temp_r - chip->temperature) > CRITICAL_USBTEMP_ABOVE_BATTEMP_1))
			&& (chip->icharging > CHARGE_CURRENT_THRESHOLD))
			|| ((((chip->usb_temp_l - chip->temperature) > CRITICAL_USBTEMP_ABOVE_BATTEMP_2) || ((chip->usb_temp_r - chip->temperature) > CRITICAL_USBTEMP_ABOVE_BATTEMP_2))
			&& (chip->icharging <= CHARGE_CURRENT_THRESHOLD)))
			&& chip->authenticate) {
			chg_err("in loop 2");
			if (count == 0) {
				last_usb_temp_r = chip->usb_temp_r;
				last_usb_temp_l = chip->usb_temp_l;
			} else {
				current_temp_r = chip->usb_temp_r;
				current_temp_l = chip->usb_temp_l;
			}
			if (((current_temp_l - last_usb_temp_l) >= CRITICAL_RISE_TEMPERATURE) || (current_temp_r - last_usb_temp_r) >= CRITICAL_RISE_TEMPERATURE) {
				for (i = 1; i < retry_cnt; i++) {
					mdelay(RETRY_CNT_DELAY);
					oppo_get_usbtemp_volt(chip);
					get_usb_temp(chip);
					if ((chip->usb_temp_r - last_usb_temp_r) >= CRITICAL_RISE_TEMPERATURE)
						count_r++;
					if ((chip->usb_temp_l - last_usb_temp_l) >= CRITICAL_RISE_TEMPERATURE)
						count_l++;
					chg_err("countl : %d",count_l);
				}
				current_temp_l = chip->usb_temp_l;
				current_temp_r = chip->usb_temp_r;
				if (((count_l >= retry_cnt) && (chip->usb_temp_l < VALID_HIGH_TEMPERATURE))
					|| ((count_r >= retry_cnt) && (chip->usb_temp_r < VALID_HIGH_TEMPERATURE))) {
					if (!IS_ERR_OR_NULL(chip->normalchg_gpio.dischg_enable)) {
						chip->dischg_flag = true;
						chg_err("dischg enable3...,current_temp_l=%d,last_usb_temp_l=%d,current_temp_r=%d,last_usb_temp_r =%d\n", 
								current_temp_l, last_usb_temp_l, current_temp_r, last_usb_temp_r);
						condition2 = true;
					}
				}
				count_r = 1;
				count_l = 1;
			}
			count++;
			if (count > total_count)
				count = 0;
		}
	//judge whether to go the action
	dischg:
		if((condition1==true || condition2==true) && chip->dischg_flag == true){
			oppo_usbtemp_dischg_action(chip);
			condition1 = false;
			condition2 = false;
		}
		msleep(delay);
		if(usbtemp_debug & OPEN_LOG_BIT){
			chg_err("usbtemp: delay %d",delay);
			chg_err("==================usbtemp_volt_l[%d], usb_temp_l[%d], usbtemp_volt_r[%d], usb_temp_r[%d]\n", 
				chip->usbtemp_volt_l,chip->usb_temp_l, chip->usbtemp_volt_r, chip->usb_temp_r);
		}
	}
	return 0;
}
#endif


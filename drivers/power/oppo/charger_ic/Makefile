ifeq ($(CONFIG_OPPO_CHARGER_MTK),y)

else ifeq ($(CONFIG_OPPO_SM6250_CHARGER),y)
ifeq ($(CONFIG_MSM_206B1),y)
	obj-y	+= oppo_mp2650.o
	obj-y	+= oppo_da9313.o
	obj-y	+= oppo_battery_sm7125_Q.o
	obj-y	+= oppo_usbtemp.o

else
	obj-y   += oppo_battery_sm6250_P.o
endif
endif 

	obj-y   += oppo_short_ic.o

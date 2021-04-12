obj-$(CONFIG_OPPO_COMMON_SOFT)	+=  device_info/
obj-$(CONFIG_OPPO_DEVICE_IFNO)	+=  project_info/
obj-$(CONFIG_RECORD_MDMRST)	+=  mdmrst/
obj-$(CONFIG_OPPO_HYPNUS)     +=  oppo_hypnus/
obj-$(CONFIG_OPPO_SHUTDOWN_DETECT)	+=  oppo_shutdown_detect/
#xjun@ODM_LQ@BSP.Bringup,2020/05/27,modified for sensor folder build -start
ifeq ($(CONFIG_MSM_206B1),y)
obj-y += sensor/
else
obj-y +=  oppo_als_cali_value/
endif
#xjun@ODM_LQ@BSP.Bringup,2020/05/27,modified for sensor folder build -end
obj-y +=  oppo_healthinfo/
obj-y +=  oppo_criticallog/



#ifdef VENDOR_EDIT
#Kun.Hu@TECH.BSP.Stability.PHOENIX_PROJECT 2019/06/15, Add for PHOENIX_PROJECT
obj-$(CONFIG_OPPO_PHOENIX)     +=  oppo_phoenix/
#endif /* VENDOR_EDIT */

#ifdef VENDOR_EDIT
#GaoTing.Gan@PSW.MultiMedia.MediaServer, 2019/03/07, Add for kevent feedback
obj-y +=  oppo_kevent_feedback/
#endif /* VENDOR_EDIT */

#ifdef VENDOR_EDIT
#zhangzongyu@BSP.Kernel.Stability, 2020/05/10, Add for dump device info
obj-$(CONFIG_OPPO_DUMP_DEVICE_INFO)	+=  dump_device_info/
#endif /* VENDOR_EDIT */

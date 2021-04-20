/*
 *  ======== ti_drivers_config.h ========
 *  Configured TI-Drivers module declarations
 *
 *  DO NOT EDIT - This file is generated for the MSP_EXP432P401R
 *  by the SysConfig tool.
 */
#ifndef ti_drivers_config_h
#define ti_drivers_config_h

#define CONFIG_SYSCONFIG_PREVIEW

#define CONFIG_MSP_EXP432P401R

#ifndef DeviceFamily_MSP432P401x
#define DeviceFamily_MSP432P401x
#endif

#include <ti/devices/DeviceFamily.h>

#include <stdint.h>

/* support C++ sources */
#ifdef __cplusplus
extern "C" {
#endif


/*
 *  ======== ADC ========
 */

/* P6.1, Touchscreen X-axis */
#define Board_ADC_KENTEC_TS_YP      0
/* P4.0, Touchscreen Y-axis */
#define Board_ADC_KENTEC_TS_XP      1


/*
 *  ======== GPIO ========
 */

/* P2.7, LCD Backlight */
#define Board_GPIO_KENTEC_LCD_BACKLIGHT     0
/* P3.5, LCD Reset */
#define Board_GPIO_KENTEC_LCD_RESET         1
/* P4.6, LCD DC */
#define Board_GPIO_KENTEC_LCD_DC            2
/* P5.0, LCD SPI Slave Select */
#define Board_GPIO_KENTEC_LCD_CS            3
/* P6.1, Touchscreen Y+ */
#define Board_GPIO_KENTEC_TS_YP             4
/* P4.0, Touchscreen X+ */
#define Board_GPIO_KENTEC_TS_XP             5
/* P3.6, Touchscreen Y- */
#define Board_GPIO_KENTEC_TS_YN             6
/* P3.7, Touchscreen X- */
#define Board_GPIO_KENTEC_TS_XN             7

/* LEDs are active high */
#define CONFIG_GPIO_LED_ON  (1)
#define CONFIG_GPIO_LED_OFF (0)

#define CONFIG_LED_ON  (CONFIG_GPIO_LED_ON)
#define CONFIG_LED_OFF (CONFIG_GPIO_LED_OFF)


/*
 *  ======== SPI ========
 */

/*
 *  MOSI: P1.6
 *  MISO: P1.7
 *  SCLK: P1.5
 *  BOOSTXL-K350QVG-S1 SPI Bus
 */
#define CONFIG_SPI_0                0


/*
 *  ======== Board_init ========
 *  Perform all required TI-Drivers initialization
 *
 *  This function should be called once at a point before any use of
 *  TI-Drivers.
 */
extern void Board_init(void);

/*
 *  ======== Board_initGeneral ========
 *  (deprecated)
 *
 *  Board_initGeneral() is defined purely for backward compatibility.
 *
 *  All new code should use Board_init() to do any required TI-Drivers
 *  initialization _and_ use <Driver>_init() for only where specific drivers
 *  are explicitly referenced by the application.  <Driver>_init() functions
 *  are idempotent.
 */
#define Board_initGeneral Board_init

#ifdef __cplusplus
}
#endif

#endif /* include guard */

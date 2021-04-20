/*
 *  ======== ti_drivers_config.c ========
 *  Configured TI-Drivers module definitions
 *
 *  DO NOT EDIT - This file is generated for the MSP_EXP432P401R
 *  by the SysConfig tool.
 */

#include <stddef.h>

#ifndef DeviceFamily_MSP432P401x
#define DeviceFamily_MSP432P401x
#endif

#include <ti/devices/DeviceFamily.h>

#include "ti_drivers_config.h"

/*
 *  =============================== ADC ===============================
 */

#include <ti/drivers/ADC.h>
#include <ti/drivers/adc/ADCMSP432.h>

#include <ti/devices/msp432p4xx/inc/msp.h>
#include <ti/devices/msp432p4xx/driverlib/adc14.h>
#include <ti/devices/msp432p4xx/driverlib/ref_a.h>

#define CONFIG_ADC_COUNT 2

/*
 *  ======== adcMSP432Objects ========
 */
ADCMSP432_Object adcMSP432Objects[CONFIG_ADC_COUNT];

/*
 *  ======== adcMSP432HWAttrs ========
 */
const ADCMSP432_HWAttrsV1 adcMSP432HWAttrs[CONFIG_ADC_COUNT] = {
    /* Board_ADC_KENTEC_TS_YP */
    /* Touchscreen X-axis */
    {
        .adcPin = ADCMSP432_P6_1_A14,
        .refVoltage = ADCMSP432_REF_VOLTAGE_VDD,
        .resolution = ADC_12BIT,
        .refExtValue = 3300000
    },
    /* Board_ADC_KENTEC_TS_XP */
    /* Touchscreen Y-axis */
    {
        .adcPin = ADCMSP432_P4_0_A13,
        .refVoltage = ADCMSP432_REF_VOLTAGE_VDD,
        .resolution = ADC_12BIT,
        .refExtValue = 3300000
    },
};

/*
 *  ======== ADC_config ========
 */
const ADC_Config ADC_config[CONFIG_ADC_COUNT] = {
    /* Board_ADC_KENTEC_TS_YP */
    /* Touchscreen X-axis */
    {
        .fxnTablePtr = &ADCMSP432_fxnTable,
        .object = &adcMSP432Objects[Board_ADC_KENTEC_TS_YP],
        .hwAttrs = &adcMSP432HWAttrs[Board_ADC_KENTEC_TS_YP]
    },
    /* Board_ADC_KENTEC_TS_XP */
    /* Touchscreen Y-axis */
    {
        .fxnTablePtr = &ADCMSP432_fxnTable,
        .object = &adcMSP432Objects[Board_ADC_KENTEC_TS_XP],
        .hwAttrs = &adcMSP432HWAttrs[Board_ADC_KENTEC_TS_XP]
    },
};

const uint_least8_t ADC_count = CONFIG_ADC_COUNT;


/*
 *  =============================== DMA ===============================
 */

#include <ti/drivers/dma/UDMAMSP432.h>
#include <ti/devices/msp432p4xx/inc/msp.h>
#include <ti/devices/msp432p4xx/driverlib/rom.h>
#include <ti/devices/msp432p4xx/driverlib/rom_map.h>
#include <ti/devices/msp432p4xx/driverlib/dma.h>

/* Ensure DMA control table is aligned as required by the uDMA Hardware */
static DMA_ControlTable dmaControlTable[16] __attribute__ ((aligned (256)));

/* This is the handler for the uDMA error interrupt. */
static void dmaErrorFxn(uintptr_t arg)
{
    int status = MAP_DMA_getErrorStatus();
    MAP_DMA_clearErrorStatus();

    /* Suppress unused variable warning */
    (void)status;

    while (1);
}

UDMAMSP432_Object udmaMSP432Object;

const UDMAMSP432_HWAttrs udmaMSP432HWAttrs = {
    .controlBaseAddr = (void *)dmaControlTable,
    .dmaErrorFxn     = (UDMAMSP432_ErrorFxn)dmaErrorFxn,
    .intNum          = INT_DMA_ERR,
    .intPriority     = (~0)
};

const UDMAMSP432_Config UDMAMSP432_config = {
    .object  = &udmaMSP432Object,
    .hwAttrs = &udmaMSP432HWAttrs
};


/*
 *  =============================== GPIO ===============================
 */

#include <ti/drivers/GPIO.h>
#include <ti/drivers/gpio/GPIOMSP432.h>

/*
 *  ======== gpioPinConfigs ========
 *  Array of Pin configurations
 */
GPIO_PinConfig gpioPinConfigs[] = {
    /* Board_GPIO_KENTEC_LCD_BACKLIGHT : LCD Backlight */
    GPIOMSP432_P2_7 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW,
    /* Board_GPIO_KENTEC_LCD_RESET : LCD Reset */
    GPIOMSP432_P3_5 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW,
    /* Board_GPIO_KENTEC_LCD_DC : LCD DC */
    GPIOMSP432_P4_6 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW,
    /* Board_GPIO_KENTEC_LCD_CS : LCD SPI Slave Select */
    GPIOMSP432_P5_0 | GPIO_CFG_OUT_STD | GPIO_CFG_OUT_STR_MED | GPIO_CFG_OUT_LOW,
    /* Board_GPIO_KENTEC_TS_YP : Touchscreen Y+ */
    GPIOMSP432_P6_1 | GPIO_DO_NOT_CONFIG,
    /* Board_GPIO_KENTEC_TS_XP : Touchscreen X+ */
    GPIOMSP432_P4_0 | GPIO_DO_NOT_CONFIG,
    /* Board_GPIO_KENTEC_TS_YN : Touchscreen Y- */
    GPIOMSP432_P3_6 | GPIO_DO_NOT_CONFIG,
    /* Board_GPIO_KENTEC_TS_XN : Touchscreen X- */
    GPIOMSP432_P3_7 | GPIO_DO_NOT_CONFIG,
};

/*
 *  ======== gpioCallbackFunctions ========
 *  Array of callback function pointers
 *
 *  NOTE: Unused callback entries can be omitted from the callbacks array to
 *  reduce memory usage by enabling callback table optimization
 *  (GPIO.optimizeCallbackTableSize = true)
 */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
    /* Board_GPIO_KENTEC_LCD_BACKLIGHT : LCD Backlight */
    NULL,
    /* Board_GPIO_KENTEC_LCD_RESET : LCD Reset */
    NULL,
    /* Board_GPIO_KENTEC_LCD_DC : LCD DC */
    NULL,
    /* Board_GPIO_KENTEC_LCD_CS : LCD SPI Slave Select */
    NULL,
    /* Board_GPIO_KENTEC_TS_YP : Touchscreen Y+ */
    NULL,
    /* Board_GPIO_KENTEC_TS_XP : Touchscreen X+ */
    NULL,
    /* Board_GPIO_KENTEC_TS_YN : Touchscreen Y- */
    NULL,
    /* Board_GPIO_KENTEC_TS_XN : Touchscreen X- */
    NULL,
};

/*
 *  ======== GPIOMSP432_config ========
 */
const GPIOMSP432_Config GPIOMSP432_config = {
    .pinConfigs = (GPIO_PinConfig *)gpioPinConfigs,
    .callbacks = (GPIO_CallbackFxn *)gpioCallbackFunctions,
    .numberOfPinConfigs = 8,
    .numberOfCallbacks = 8,
    .intPriority = (~0)
};


/*
 *  =============================== Power ===============================
 */

#include <ti/drivers/Power.h>
#include <ti/drivers/power/PowerMSP432.h>
extern void PowerMSP432_initPolicy(void);
extern void PowerMSP432_sleepPolicy(void);

const PowerMSP432_ConfigV1 PowerMSP432_config = {
    .policyInitFxn         = PowerMSP432_initPolicy,
    .policyFxn             = PowerMSP432_sleepPolicy,
    .initialPerfLevel      = 3,
    .enablePolicy          = true,
    .enablePerf            = true,
    .enableParking         = false,
    .resumeShutdownHookFxn = NULL,
    .customPerfLevels      = NULL,
    .numCustom             = 0,
    .useExtendedPerf       = false,
    .configurePinHFXT      = false,
    .HFXTFREQ              = 0,
    .bypassHFXT            = false,
    .configurePinLFXT      = false,
    .bypassLFXT            = false,
    .LFXTDRIVE             = 0,
    .enableInterruptsCS    = false,
    .priorityInterruptsCS  = (~0),
    .isrCS                 = NULL
};


/*
 *  =============================== SPI ===============================
 */

#include <ti/drivers/SPI.h>
#include <ti/drivers/spi/SPIMSP432DMA.h>

#include <ti/devices/msp432p4xx/inc/msp.h>
#include <ti/devices/msp432p4xx/driverlib/dma.h>
#include <ti/devices/msp432p4xx/driverlib/interrupt.h>
#include <ti/devices/msp432p4xx/driverlib/spi.h>

#define CONFIG_SPI_COUNT 1

/*
 *  ======== spiMSP432DMAObjects ========
 */
SPIMSP432DMA_Object spiMSP432DMAObjects[CONFIG_SPI_COUNT];

/*
 *  ======== spiMSP432DMAHWAttrs ========
 */
const SPIMSP432DMA_HWAttrsV1 spiMSP432DMAHWAttrs[CONFIG_SPI_COUNT] = {
    /* CONFIG_SPI_0 */
    /* BOOSTXL-K350QVG-S1 SPI Bus */
    {
        .baseAddr = EUSCI_B0_BASE,
        .bitOrder = EUSCI_B_SPI_MSB_FIRST,
        .clockSource = EUSCI_B_SPI_CLOCKSOURCE_SMCLK,
        .defaultTxBufValue = ~0,
        .intPriority = (~0),
        .dmaIntNum = INT_DMA_INT0,
        .rxDMAChannelIndex = DMA_CH1_EUSCIB0RX0,
        .txDMAChannelIndex = DMA_CH0_EUSCIB0TX0,
        .pinMode = EUSCI_SPI_3PIN,
        .clkPin  = SPIMSP432DMA_P1_5_UCB0CLK,
        .simoPin = SPIMSP432DMA_P1_6_UCB0SIMO,
        .somiPin = SPIMSP432DMA_P1_7_UCB0SOMI,
        .stePin  = SPIMSP432DMA_PIN_NO_CONFIG,
        .minDmaTransferSize = 10,
    },
};

/*
 *  ======== SPI_config ========
 */
const SPI_Config SPI_config[CONFIG_SPI_COUNT] = {
    /* CONFIG_SPI_0 */
    /* BOOSTXL-K350QVG-S1 SPI Bus */
    {
        .fxnTablePtr = &SPIMSP432DMA_fxnTable,
        .object = &spiMSP432DMAObjects[CONFIG_SPI_0],
        .hwAttrs = &spiMSP432DMAHWAttrs[CONFIG_SPI_0]
    },
};

const uint_least8_t SPI_count = CONFIG_SPI_COUNT;


#include <ti/drivers/Board.h>

/*
 *  ======== Board_initHook ========
 *  Perform any board-specific initialization needed at startup.  This
 *  function is declared weak to allow applications to override it if needed.
 */
void __attribute__((weak)) Board_initHook(void)
{
}

/*
 *  ======== Board_init ========
 *  Perform any initialization needed before using any board APIs
 */
void Board_init(void)
{
    /* ==== /ti/drivers/Power initialization ==== */
    Power_init();

    Board_initHook();
}

#ifndef _VARIANT_PROMICRO_DIY_
#define _VARIANT_PROMICRO_DIY_

/** Master clock frequency */
#define VARIANT_MCK (64000000ul)

#define USE_LFXO // Board uses 32khz crystal for LF
//#define USE_LFRC // Board uses RC for LF

#define PROMICRO_DIY_TCXO

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/

#include "WVariant.h"

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#define PINS_COUNT (48)
#define NUM_DIGITAL_PINS (48)
#define NUM_ANALOG_INPUTS (1)
#define NUM_ANALOG_OUTPUTS (0)

// Pin 13 enables 3.3V periphery. If the Lora module is on this pin, then it should stay enabled at all times.
#define PIN_3V3_EN (0 + 13) // P0.13

// Analog pins
#define BATTERY_PIN (0 + 31) // P0.31 Battery ADC
#define ADC_CHANNEL ADC1_GPIO4_CHANNEL
#define ADC_RESOLUTION 14
#define BATTERY_SENSE_RESOLUTION_BITS 12
#define BATTERY_SENSE_RESOLUTION 4096.0
// Definition of milliVolt per LSB => 3.0V ADC range and 12-bit ADC resolution = 3000mV/4096
#define VBAT_MV_PER_LSB (0.73242188F)
// Voltage divider value => 1.5M + 1M voltage divider on VBAT = (1.5M / (1M + 1.5M))
#define VBAT_DIVIDER (0.5F)
// Compensation factor for the VBAT divider
#define VBAT_DIVIDER_COMP (2.005)
// Fixed calculation of milliVolt from compensation value
#define REAL_VBAT_MV_PER_LSB (VBAT_DIVIDER_COMP * VBAT_MV_PER_LSB)
#undef AREF_VOLTAGE
#define AREF_VOLTAGE 3.0
#define VBAT_AR_INTERNAL AR_INTERNAL_3_0
#define ADC_MULTIPLIER VBAT_DIVIDER_COMP // REAL_VBAT_MV_PER_LSB
#define VBAT_RAW_TO_SCALED(x) (REAL_VBAT_MV_PER_LSB * x)

// WIRE IC AND IIC PINS
#define WIRE_INTERFACES_COUNT 1

#define PIN_WIRE_SDA (32 + 4) // P1.04
#define PIN_WIRE_SCL (0 + 11) // P0.11

// LED
#define PIN_LED1 (0 + 15) // P0.15
// Actually red
#define LED_BLUE PIN_LED1
#define LED_STATE_ON 1 // State when LED is lit
#define LED_LORA PIN_LED1

// Button
#define BUTTON_PIN (32 + 0) // P1.00

// GPS
#define GPS_TX_PIN (0 + 20) // P0.20 - This is data from the MCU
#define GPS_RX_PIN (0 + 22) // P0.22 - This is data from the GNSS

#define PIN_GPS_EN (0 + 24) // P0.24
#define GPS_UBLOX
// define GPS_DEBUG

// UART interfaces
#define PIN_SERIAL1_TX GPS_TX_PIN
#define PIN_SERIAL1_RX GPS_RX_PIN

#define PIN_SERIAL2_RX (0 + 6) // P0.06
#define PIN_SERIAL2_TX (0 + 8) // P0.08

// Serial interfaces
#define SPI_INTERFACES_COUNT 1

#define PIN_SPI_MISO (0 + 2)   // P0.02
#define PIN_SPI_MOSI (32 + 15) // P1.15
#define PIN_SPI_SCK (32 + 11)  // P1.11

#define LORA_MISO PIN_SPI_MISO
#define LORA_MOSI PIN_SPI_MOSI
#define LORA_SCK PIN_SPI_SCK
#define LORA_CS (32 + 13) // P1.13

// LORA MODULES
#define USE_SX1262

#define LORA_DIO0 (0 + 29) // P0.29 BUSY
#define LORA_DIO1 (0 + 10) // P0.10 IRQ
#define LORA_RESET (0 + 9) // P0.09 NRST


// SX126X CONFIG
#define SX126X_CS (32 + 13)      // P1.13 FIXME - we really should define LORA_CS instead
#define SX126X_DIO1 (0 + 10)     // P0.10 IRQ
#define SX126X_DIO2_AS_RF_SWITCH
#define SX126X_BUSY (0 + 29)     // P0.29
#define SX126X_RESET (0 + 9)     // P0.09
#define SX126X_RXEN RADIOLIB_NC
#define SX126X_TXEN RADIOLIB_NC  // Assuming that DIO2 is connected to TXEN pin. If not, TXEN must be connected.
#define SX126X_DIO3_TCXO_VOLTAGE 1.8
//#define TCXO_OPTIONAL // make it so that the firmware can try both TCXO and XTAL

// E-Ink DIY
#define PIN_EINK_CS (32 + 7)
#define PIN_EINK_DC (32 + 2)
#define PIN_EINK_RES (32 + 1)
#define PIN_EINK_BUSY (32 + 6)

#define HAS_SCREEN 0
#define HAS_GPS 0
#define HAS_SENSOR 0

#ifdef __cplusplus
}
#endif

/*----------------------------------------------------------------------------
 *        Arduino objects - C++ only
 *----------------------------------------------------------------------------*/

#endif

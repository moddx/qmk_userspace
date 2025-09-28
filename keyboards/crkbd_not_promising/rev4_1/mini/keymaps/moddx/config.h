/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#undef LAYOUT
#define LAYOUT LAYOUT_split_3x5_3

#undef SERIAL_USART_TX_PIN
#undef I2C1_SDA_PIN
#undef I2C1_SCL_PIN

/*
"matrix_pins": {
  "cols": ["GP29", "GP28", "GP27", "GP26", "GP18", "GP20"],    // Adafruit KB2040
  // "cols": ["GP29", "GP28", "GP27", "GP26", "GP22", "GP20"], // Sparkfun RP2040
  "rows": ["GP4", "GP5", "GP6", "GP7"]
}
*/
#undef MATRIX_ROW_PINS
#define MATRIX_ROW_PINS {GP4, GP5, GP6, GP7}
#undef MATRIX_COL_PINS
#define MATRIX_COL_PINS {GP29, GP28, GP27, GP26, GP18, GP20}


#undef SPLIT_HAND_PIN
#undef ENCODER_A_PINS
#undef ENCODER_B_PINS
#undef ENCODER_A_PINS_RIGHT
#undef ENCODER_B_PINS_RIGHT

#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN GP1


/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Handedness. */
#define MASTER_LEFT

#undef USB_VBUS_PIN
#define USB_VBUS_PIN GP0

#define USE_SERIAL
/* serial.c configuration (for split keyboard). */
//#define SOFT_SERIAL_PIN GP1

/* Reset. */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
//#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
//#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

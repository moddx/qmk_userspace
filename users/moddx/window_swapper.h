#pragma once

#include QMK_KEYBOARD_H
#include "process_record.h"

process_record_result_t process_window_swapper(uint16_t keycode, keyrecord_t *record);

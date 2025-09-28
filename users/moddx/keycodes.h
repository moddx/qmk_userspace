#pragma once

#include QMK_KEYBOARD_H

enum custom_keycodes {
    #if defined(KEYBOARD_bastardkb_charybdis_3x5_v2_elitec) || (KEYBOARD_bastardkb_dilemma_3x5_3)
    START_RANGE = QK_USER,
    #else
    START_RANGE = QK_USER,
    DPI_MOD,
    DPI_RMOD,
    DRGSCRL,
    SNIPING,
    #endif
    EMAIL,
    TOGGLE_LEFT_ENCODER,
    MC_SWLE,
    MC_SWRI,
    KC_ACCEL,
    MY_COPY,
    MY_PASTE,
    MY_CUT,
    MY_UNDO,
    MY_SAVE,
    MY_CMD_CTRL,
    KEYCODES_RANGE
};

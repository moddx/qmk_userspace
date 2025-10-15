#include "moddx.h"
#include "keycodes.h"
#include "pointing/pointing.h"
#include "window_swapper.h"

#include "keymap_german.h"
#include "sendstring_german.h"

#if (__has_include("secrets.h") && !defined(NO_SECRETS))
#include "secrets.h"
#else
#include "secrets_placeholder.h"
#endif


//
// OVERRIDES
//
// Dot/Comma on L3
const key_override_t ctrl_dot_override = ko_make_with_layers(MOD_MASK_CTRL, KC_DOT, KC_COMM, (1 << _L3));
const key_override_t shift_dot_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_DOT, KC_COMM, (1 << _L3));
// Media Key on L1
const key_override_t play_next_override = ko_make_with_layers(MOD_MASK_CTRL, KC_MPLY, KC_MNXT, (1 << _L1));
const key_override_t play_prev_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_MPLY, KC_MPRV, (1 << _L1));

// L4
// ß
const key_override_t excl_quest_override = ko_make_with_layers(MOD_MASK_SHIFT, LSFT(KC_1), S(DE_SS), (1 << _L4));
// '
const key_override_t apos_single_override = ko_make_with_layers(MOD_MASK_SHIFT, LSFT(KC_2), S(DE_HASH), (1 << _L4));
// `
const key_override_t apos_backtick_override = ko_make_with_layers(MOD_MASK_ALT, LSFT(KC_2), DE_GRV, (1 << _L4));
// ´
const key_override_t apos_tick_override = ko_make_with_layers(MOD_MASK_ALT, LSFT(KC_3), DE_ACUT, (1 << _L4));
// ^
const key_override_t circ_override = ko_make_with_layers(MOD_MASK_ALT, LSFT(KC_7), DE_CIRC, (1 << _L4));
// °
const key_override_t deg_override = ko_make_with_layers(MOD_MASK_ALT, LSFT(KC_9), DE_DEG, (1 << _L4));
// backslash
const key_override_t sls_bsls_override = ko_make_with_layers(MOD_MASK_SHIFT, LSFT(KC_7), DE_BSLS, (1 << _L4));

const key_override_t *key_overrides[] = {
    &ctrl_dot_override,
    &shift_dot_override,
    &play_next_override,
    &play_prev_override,
    // L4
    &excl_quest_override,
    &apos_single_override,
    &apos_backtick_override,
    &apos_tick_override,
    &circ_override,
    &deg_override,
    &sls_bsls_override,
    NULL // Null terminate the array of overrides!
};

// #if defined (KEYBOARD_bastardkb_dilemma_3x5_3)
// #define LAYOUT LAYOUT_split_3x5_3
// #endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Default, L0
	[_DEFAULT] = LAYOUT(
		KC_X,         KC_V,          KC_L,          KC_C,          KC_W,           KC_K,   KC_H,   KC_G,    KC_F,    KC_Q,
		LALT_T(KC_U), LT(_L4, KC_I), LT(_L5, KC_A), LT(_L3, KC_E), KC_O,           KC_S,   KC_N,   KC_R,    KC_T,    KC_D,
		LSFT_T(DE_Y), MO(_MOUSE),    QK_LEAD,       KC_P,          DE_Z,           KC_B,   KC_M,   KC_COMM, KC_DOT,  RSFT_T(KC_J),
		                TOGGLE_LEFT_ENCODER,        KC_LCTL,       MO(_L1),        KC_SPC, MO(_L2), KC_MUTE
    ),

    [_HL] = LAYOUT(
		KC_TAB,      KC_Q, KC_W, KC_E, KC_R,           KC_Z,   KC_U,   KC_I,    KC_O,    KC_P,
		KC_LSFT,     KC_A, KC_S, KC_D, KC_F,           KC_H,   KC_J,   KC_K,    KC_L,    QK_LEAD,
		KC_LCTL,     DE_Y, DE_5, KC_4, KC_3,           KC_N,   KC_M,   KC_COMM, KC_DOT,  RSFT_T(DE_MINS),
		                   KC_2, KC_1, KC_SPC,         KC_ESC, TG(_HL), KC_TRNS
    ),

    // _L1
	[_L1] = LAYOUT(
        KC_TAB,      KC_ESC,  KC_ENT,   MY_UNDO,   KC_INS,        DM_REC1, DE_HASH,       DE_LCBR, DE_RCBR, KC_MPLY,
		KC_LCTL,     KC_SPC,  MY_SAVE,  KC_HOME,   KC_END,        KC_LEFT, KC_DOWN,       KC_UP,   KC_RGHT, DE_LPRN,
		KC_LSFT,     MY_CUT,  MY_COPY,  MY_PASTE,  OSM(MOD_LSFT), KC_DEL,  KC_BSPC,       DE_LBRC, DE_RBRC, DE_RPRN,
		                      KC_TRNS,  KC_TRNS,   KC_TRNS,       KC_LALT, OSM(MOD_LGUI), KC_TRNS
    ),

	// _L2
	[_L2] = LAYOUT(
		EMAIL,          MY_BACKSLASH, DE_EQL,  DE_AMPR, MY_TILDE,     DM_PLY1, LSFT(KC_F3), DE_ASTR, KC_F3,   DE_PLUS,
		MY_MONKEY,      DE_LABK,     DE_RABK, DE_MINS, DE_PIPE,       MC_SWLE, KC_PGDN,     KC_PGUP, MC_SWRI, KC_TRNS,
		LSFT_T(KC_APP), LALT(KC_F4), KC_NO,   KC_NO,   KC_MISSION_CONTROL, DE_SS,   DE_UDIA,     DE_ODIA, DE_ADIA, KC_RSFT,
		                             KC_TRNS, KC_CAPS, KC_TRNS,       KC_TRNS, KC_TRNS, KC_TRNS
    ),

	// _L3 NUM
	[_L3] = LAYOUT(
		TG(_HL),       KC_TRNS,       EH_RGHT,       EH_LEFT,       QK_BOOT,              DE_SLSH, KC_7,   KC_8,    KC_9,  DE_PLUS,
		OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LCTL), KC_TRNS,       EE_CLR,              DE_ASTR, KC_4,   KC_5,    KC_6,  DE_MINS,
		OSM(MOD_LSFT), KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,              KC_BSPC, KC_1,   KC_2,    KC_3,  KC_RSFT,
                                      OSM(MOD_LGUI), OSM(MOD_LCTL), KC_TRNS,              KC_0,    KC_DOT, KC_TRNS
    ),

    // _L4 NUM SYMS
	[_L4] = LAYOUT(
		KC_TRNS,       KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,              KC_NO,      LSFT(KC_7),  LSFT(KC_8),  LSFT(KC_9), KC_NO,
		OSM(MOD_LALT), KC_TRNS,  OSM(MOD_LCTL), MO(_L5),       KC_TRNS,              KC_NO,      LSFT(KC_4),  LSFT(KC_5),  LSFT(KC_6), KC_NO,
		OSM(MOD_LSFT), KC_TRNS,  KC_TRNS,       KC_TRNS,       KC_TRNS,              KC_BSPC,    LSFT(KC_1),  LSFT(KC_2),  LSFT(KC_3), KC_NO,
		                         OSM(MOD_LGUI), OSM(MOD_LCTL), KC_TRNS,              LSFT(KC_0), KC_DOT, KC_TRNS
    ),

	// _L5 F-Keys
	[_L5] = LAYOUT(
		KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,          KC_TRNS, KC_F7,   KC_F8,   KC_F9,   KC_F10,
		OSM(MOD_LALT), OSM(MOD_LSFT), KC_TRNS,       KC_TRNS,       KC_TRNS,          KC_TRNS, KC_F4,   KC_F5,   KC_F6,   KC_F11,
		OSM(MOD_LSFT), KC_TRNS,       KC_TRNS,       KC_TRNS,       KC_TRNS,          KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F12,
		                              OSM(MOD_LGUI), OSM(MOD_LCTL), KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
    ),

    // _MOUSE
	[_MOUSE] = LAYOUT(
        KC_NO,         MS_BTN2,       MS_BTN3,       MS_BTN1,       KC_ACCEL,         KC_NO,   KC_NO,   DPI_RMOD,  DPI_MOD, KC_NO,
		KC_LALT,       LT(_L4, KC_I), LT(_L5, KC_A), LT(_L3, KC_E), KC_NO,            KC_NO,   MS_BTN1, MS_BTN3,   MS_BTN2, KC_NO,
		KC_LSFT,       KC_TRNS,       SNIPING,       DRGSCRL,       KC_NO,            KC_NO,   DRGSCRL, KC_NO,     KC_NO,   KC_NO,
                                      KC_LSFT,       KC_LCTL,       MO(_L1),          KC_LALT, KC_TRNS, KC_TRNS
    )

};

bool leftEncoderToggled = false;
bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 0: // Left-half encoder, mouse scroll.
            if (leftEncoderToggled) {
                tap_code(clockwise ? KC_DOWN: KC_UP);
            } else {
                tap_code(clockwise ? KC_RGHT: KC_LEFT);
            }
            break;
        case 1: // Right-half encoder, volume control.
            tap_code(clockwise ? KC_AUDIO_VOL_UP : KC_AUDIO_VOL_DOWN);
            break;
    }
    return true;
}

void handleMacOsCompat(os_variant_t os, uint16_t keycode) {
    if (os == OS_MACOS) {
        tap_code16(LCMD(keycode));
    } else {
        tap_code16(LCTL(keycode));
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_pointing(keycode, record)
        || process_window_swapper(keycode, record) != PROCESS_RECORD_CONTINUE
        ) { return false; }
    //if (!process_caps_word(keycode, record)) { return false; }

    os_variant_t os = detected_host_os();

    switch (keycode) {
    case EMAIL:
        if (record->event.pressed) {
            // when keycode EMAIL is pressed
            SEND_STRING(SECRET_EMAIL);
        } else {
            // when keycode EMAIL is released
        }
        break;
    case MY_COPY:
        if (record->event.pressed) {
            handleMacOsCompat(os, KC_C);
        }
        break;
    case MY_PASTE:
        if (record->event.pressed) {
            handleMacOsCompat(os, KC_V);
        }
        break;
    case MY_CUT:
        if (record->event.pressed) {
            handleMacOsCompat(os, KC_X);
        }
        break;
    case MY_UNDO:
        if (record->event.pressed) {
            handleMacOsCompat(os, DE_Z);
        }
        break;
    case MY_SAVE:
        if (record->event.pressed) {
            handleMacOsCompat(os, KC_S);
        }
        break;
    case MY_CMD_CTRL:
        uint16_t modifier = os == OS_MACOS ? MOD_MASK_GUI : MOD_MASK_CTRL;
        if (record->event.pressed) {
            register_mods(modifier);
        } else {
            unregister_mods(modifier);
        }
        break;
    case MY_TILDE:
        if (record->event.pressed) {
            os == OS_MACOS ? tap_code16(LOPT(KC_N)) : tap_code16(DE_TILD);
        }
        break;
    case MY_BACKSLASH:
        if (record->event.pressed) {
            os == OS_MACOS ? tap_code16(LOPT(LSFT(KC_7))) : tap_code16(DE_BSLS);
        }
        break;
    case MY_MONKEY:
        if (record->event.pressed) {
            os == OS_MACOS ? tap_code16(LOPT(KC_L)) : tap_code16(DE_AT);
        }
        break;
    case TOGGLE_LEFT_ENCODER:
        if (record->event.pressed) {
            leftEncoderToggled = !leftEncoderToggled;
        }
        break;
    case LSFT_T(DE_Z):
        if (record->tap.count && record->event.pressed) {
            tap_code16(LCTL(DE_Z));  // Send CTRL+Z on tap
            return false;        // Return false to ignore further processing of key
        }
        break;
    case LCTL_T(DE_AT):
        if (record->tap.count && record->event.pressed) {
            tap_code16(DE_AT);  // Send @ on tap
            return false;       // Return false to ignore further processing of key
        }
        break;
    }

    return true;
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(DE_Y):
        case RSFT_T(KC_J):
            // Immediately select the hold action when another key is pressed.
            return false;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(DE_Y):
        case RSFT_T(KC_J):
            // Do select the hold action when another key is tapped.
            return true;
        default:
            // Do not select the hold action when another key is tapped.
            return false;
    }
}


void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_S)) {
      tap_code16(DE_SS);
    }

    if (leader_sequence_one_key(KC_Q)) {
      tap_code16(S(DE_SS));
    }

    if (leader_sequence_one_key(KC_E)) {
      tap_code16(DE_EURO);
    }

    if (leader_sequence_one_key(KC_P)) {
      tap_code16(C(S(A(KC_Q))));
    }

    if (leader_sequence_one_key(KC_N)) {
      SEND_STRING(SECRET_JENKINS);
      tap_code(KC_ENTER);
    }
}

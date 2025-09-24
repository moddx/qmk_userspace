
ifdef rp2040
	#MCU = RP2040
	#BOOTLOADER = rp2040
	#ALLOW_WARNINGS = yes
	#PICO_INTRINSICS_ENABLED = no # ATM Unsupported by ChibiOS
	SERIAL_DRIVER = vendor
	WS2812_DRIVER = vendor
#	POINTING_DEVICE_ENABLE = no
	DEFAULT_FOLDER = crkbd/rev1
	NKRO_ENABLE = yes
endif

ifdef cnano
	EXTRAFLAGS += -flto
	LTO_ENABLE = yes
#	POINTING_DEVICE_ENABLE = yes
	NKRO_ENABLE = no
endif



# Build Options
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration

AUDIO_ENABLE = no           # Audio output

# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
#SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
#BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
#RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
#RGBLIGHT_SUPPORTED = no     # RGB underglow is supported, but not enabled by default
#RGB_MATRIX_ENABLE = no      # Enable keyboard RGB matrix functionality
#RGB_MATRIX_SUPPORTED = no   # RGB matrix is supported and enabled by default

LAYOUTS = split_3x5_3

# moddx
KEY_OVERRIDE_ENABLE = yes
TAP_DANCE_ENABLE = no
CAPS_WORD_ENABLE = no
LEADER_ENABLE = yes
COMBO_ENABLE = yes


INTROSPECTION_KEYMAP_C = users/moddx/combos.c

KEYMAP_C = users/moddx/moddx.c
#SRC += users/moddx/tapdances.c
#SRC += users/moddx/combos.c
SRC += users/moddx/pointing/pointing.c
SRC += users/moddx/os_toggle.c
SRC += users/moddx/window_swapper.c

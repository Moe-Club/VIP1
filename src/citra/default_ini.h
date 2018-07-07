// Copyright 2014 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#pragma once

namespace DefaultINI {

const char* sdl2_config_file = R"(
[ControlPanel]
# Shared Page - Enable 3D
sp_enable_3d =

# Power - Adapter connected
p_adapter_connected =

# Power - Battery charging
p_battery_charging =

# Power - Battery level
p_battery_level =

# Network - Wi-Fi status
n_wifi_status =

# Network - Wi-Fi link level
n_wifi_link_level =

# Network - State
n_state =

[Controls]
# The input devices and parameters for each 3DS native input
# It should be in the format of "engine:[engine_name],[param1]:[value1],[param2]:[value2]..."
# Escape characters $0 (for ':'), $1 (for ',') and $2 (for '$') can be used in values

# for button input, the following devices are available:
#  - "keyboard" (default) for keyboard input. Required parameters:
#      - "code": the code of the key to bind
#  - "sdl" for joystick input using SDL. Required parameters:
#      - "joystick": the index of the joystick to bind
#      - "button"(optional): the index of the button to bind
#      - "hat"(optional): the index of the hat to bind as direction buttons
#      - "axis"(optional): the index of the axis to bind
#      - "direction"(only used for hat): the direction name of the hat to bind. Can be "up", "down", "left" or "right"
#      - "threshold"(only used for axis): a float value in (-1.0, 1.0) which the button is
#          triggered if the axis value crosses
#      - "direction"(only used for axis): "+" means the button is triggered when the axis value
#          is greater than the threshold; "-" means the button is triggered when the axis value
#          is smaller than the threshold
button_a=
button_b=
button_x=
button_y=
button_up=
button_down=
button_left=
button_right=
button_l=
button_r=
button_start=
button_select=
button_zl=
button_zr=
button_home=

# for analog input, the following devices are available:
#  - "analog_from_button" (default) for emulating analog input from direction buttons. Required parameters:
#      - "up", "down", "left", "right": sub-devices for each direction.
#          Should be in the format as a button input devices using escape characters, for example, "engine$0keyboard$1code$00"
#      - "modifier": sub-devices as a modifier.
#      - "modifier_scale": a float number representing the applied modifier scale to the analog input.
#          Must be in range of 0.0-1.0. Defaults to 0.5
#  - "sdl" for joystick input using SDL. Required parameters:
#      - "joystick": the index of the joystick to bind
#      - "axis_x": the index of the axis to bind as x-axis (default to 0)
#      - "axis_y": the index of the axis to bind as y-axis (default to 1)
circle_pad=
c_stick=

# for motion input, the following devices are available:
#  - "motion_emu" (default) for emulating motion input from mouse input. Required parameters:
#      - "update_period": update period in milliseconds (default to 100)
#      - "sensitivity": the coefficient converting mouse movement to tilting angle (default to 0.00125)
#      - "tilt_clamp": the max value of the tilt angle in degrees (default to 90)
motion_device=

# for touch input, the following devices are available:
#  - "emu_window" (default) for emulating touch input from mouse input to the emulation window. No parameters required
touch_device=

[Core]
# Whether to use the Just-In-Time (JIT) compiler for CPU emulation
# 0: Interpreter (slow), 1 (default): JIT (fast)
use_cpu_jit =

# Software keyboard implementation
# 0: StdIn (default)
swkbd_implementation =

[Renderer]
# Whether to use software or hardware rendering.
# 0: Software, 1 (default): OpenGL
use_hw_renderer =

# Whether to use hardware shaders to emulate 3DS shaders
# 0: Software, 1 (default): Hardware
use_hw_shader =

# Whether to use accurate multiplication in hardware shaders
# 0: Off (Default. Faster, but causes issues in some games) 1: On (Slower, but correct)
shaders_accurate_mul =

# Whether to fallback to software for geometry shaders
# 0: Off (Faster, but causes issues in some games) 1: On (Default. Slower, but correct)
shaders_accurate_gs =

# Whether to use the Just-In-Time (JIT) compiler for shader emulation
# 0: Interpreter (slow), 1 (default): JIT (fast)
use_shader_jit =

# Resolution scale factor
# 0: Auto (scales resolution to window size), 1: Native 3DS screen resolution, Otherwise a scale
# factor for the 3DS resolution
resolution_factor =

# Whether to enable V-Sync (caps the framerate at 60FPS) or not.
# 0 (default): Off, 1: On
use_vsync =

# Ignore format reinterpretation
# 0 (default): disabled, 1: enabled
use_bos =

# Turns on the frame limiter, which will limit frames output to the target game speed
# 0: Off, 1: On (default)
use_frame_limit =

# Limits the speed of the game to run no faster than this value as a percentage of target speed
# 1 - 9999: Speed limit as a percentage of target game speed. 100 (default)
frame_limit =

# The clear color for the renderer. What shows up on the sides of the bottom screen.
# Must be in range of 0.0-1.0. Defaults to 1.0 for all.
bg_red =
bg_blue =
bg_green =

# Toggles Stereoscopic 3D
# 0 (default): Off, 1: On
toggle_3d =

# Change 3D Intensity
# 0 - 100: Intensity. 0 (default)
factor_3d =

[Layout]
# Layout for the screen inside the render window.
# 0 (default): Default Top Bottom Screen, 1: Single Screen Only, 2: Large Screen Medium Screen, 3: Large Screen Small Screen, 4: Side by Side
layout_option =

# Toggle custom layout (using the settings below) on or off.
# 0 (default): Off, 1: On
custom_layout =

# Screen placement when using Custom layout option
# 0x, 0y is the top left corner of the render window.
custom_top_left =
custom_top_top =
custom_top_right =
custom_top_bottom =
custom_bottom_left =
custom_bottom_top =
custom_bottom_right =
custom_bottom_bottom =

# Swaps the prominent screen with the other screen.
# For example, if Single Screen is chosen, setting this to 1 will display the bottom screen instead of the top screen.
# 0 (default): Top Screen is prominent, 1: Bottom Screen is prominent
swap_screen =

[Audio]
# Which audio output engine to use.
# auto (default): Auto-select, null: No audio output, sdl2: SDL2 (if available)
output_engine =

# Whether or not to enable the audio-stretching post-processing effect.
# This effect adjusts audio speed to match emulation speed and helps prevent audio stutter,
# at the cost of increasing audio latency.
# 0: No, 1 (default): Yes
enable_audio_stretching =

# Which audio device to use.
# auto (default): Auto-select
output_device =

# Output volume.
# 1.0 (default): 100%, 0.0; mute
volume =

[Data Storage]
# Whether to create a virtual SD card.
# 1 (default): Yes, 0: No
use_virtual_sd =

# The SD card root
# empty: user directory/sdmc
sd_card_root =

[System]
# The system region that Citra will use during emulation
# -1: Auto-select (default), 0: JPN, 1: USA, 2: EUR, 3: AUS, 4: CHN, 5: KOR, 6: TWN
region_value =

# Enable New Mode
# 0 (default): disable, 1: enable
enable_new_mode =

[Camera]
# Which camera engine to use for the right outer camera
# blank (default): a dummy camera that always returns black image
camera_outer_right_name =

# A config string for the right outer camera. Its meaning is defined by the camera engine
camera_outer_right_config =

# The image flip to apply
# 0: None (default), 1: Horizontal, 2: Vertical, 3: Reverse
camera_outer_right_flip =

# ... for the left outer camera
camera_outer_left_name =
camera_outer_left_config =
camera_outer_left_flip =

# ... for the inner camera
camera_inner_name =
camera_inner_config =
camera_inner_flip =

[Miscellaneous]
# A filter which removes logs below a certain logging level.
# Examples: *:Debug Kernel.SVC:Trace Service.*:Critical
log_filter = *:Info

[WebService]
# Endpoint URL to verify the username and token
verify_endpoint_url = https://api.citra-emu.org/profile
# Endpoint URL for announcing public rooms
announce_multiplayer_room_endpoint_url = https://api.citra-emu.org/lobby
# Username and token for Citra Web Service
# See https://services.citra-emu.org/ for more info
citra_username =
citra_token =

[Hacks]
# Priority Boost
# 0: (default) disable, 1: enable
priority_boost =

# CPU JIT Hacks
# 0: disable, 1 (default): enable
cpu_jit_hacks =
)";
}
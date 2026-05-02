# MK12 Camera Plugin for UEVR

This plugin provides Lua bindings for VR overlay component functions, allowing Lua scripts to control UI overlay properties without requiring UEVR to be rebuilt.

## Features

The plugin exposes the following VR functions to Lua:

**World Scale:**
- `vr.get_world_scale()` / `vr.set_world_scale(scale)`

**UI Overlay:**
- `vr.get_ui_offset_x()` / `vr.set_ui_offset_x(value)`
- `vr.get_ui_offset_y()` / `vr.set_ui_offset_y(value)`
- `vr.get_ui_offset_distance()` / `vr.set_ui_offset_distance(value)`
- `vr.get_ui_size()` / `vr.set_ui_size(value)`
- `vr.get_ui_follows_view()` / `vr.set_ui_follows_view(value)`
- `vr.get_ui_overlay_type()` / `vr.set_ui_overlay_type(value)`
- `vr.get_ui_yaw()` / `vr.set_ui_yaw(value)`
- `vr.get_ui_roll()` / `vr.set_ui_roll(value)`
- `vr.get_ui_pitch()` / `vr.set_ui_pitch(value)`
- `vr.get_ui_cylinder_angle()` / `vr.set_ui_cylinder_angle(value)`

## Building

### Prerequisites

- CMake 3.15 or higher
- Visual Studio 2019 or later (with C++ support)
- UEVR source code (for API headers)

### Build Steps

1. Navigate to the plugin directory:
   ```bash
   cd c:\UEVR\UEVR\plugins\MK12CameraPlugin
   ```

2. Create a build directory:
   ```bash
   mkdir build
   cd build
   ```

3. Configure with CMake:
   ```bash
   cmake ..
   ```

4. Build:
   ```bash
   cmake --build . --config Release
   ```

5. The built DLL will be in `../bin/MK12CameraPlugin.dll`

## Installation

1. Copy `MK12CameraPlugin.dll` to your UEVR plugins directory:
   ```
   c:\Users\janbl\AppData\Roaming\UnrealVRMod\plugins\
   ```

2. UEVR will automatically load the plugin on startup.

## Usage in Lua Scripts

The plugin automatically registers the `vr` table with overlay functions when loaded. Your Lua scripts can use these functions directly:

```lua
-- Example usage in your Lua script
local current_offset_x = vr.get_ui_offset_x()
vr.set_ui_offset_x(100.0)

vr.set_ui_size(0.5)
vr.set_ui_yaw(45.0)
vr.set_ui_follows_view(true)
```

## Migration from VRBinding.cpp

If you were previously using the VRBinding.cpp modifications in UEVR core:

1. Remove the custom functions from `c:\UEVR\UEVR\src\mods\bindings\VRBinding.cpp`
2. Rebuild UEVR without your custom modifications
3. Build and install this plugin
4. Your Lua scripts will continue to work without changes

## Benefits

- **No UEVR rebuilds needed**: Update your Lua scripts without recompiling UEVR
- **Modular**: Plugin can be updated independently of UEVR
- **Portable**: Share your plugin with others without sharing modified UEVR builds
- **Clean separation**: Your game-specific logic is separate from UEVR core

## Troubleshooting

If the plugin doesn't load:

1. Check UEVR logs for error messages
2. Ensure the plugin DLL is in the correct plugins directory
3. Verify UEVR version compatibility (requires UEVR 2.39.0 or higher)
4. Check that the plugin exports the required functions: `uevr_plugin_initialize` and `uevr_plugin_required_version`

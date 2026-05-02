/*
MK12 Camera Plugin - Plugin for UEVR
This plugin provides Lua bindings for VR overlay component functions
*/

#include <windows.h>
#include <uevr/API.h>
extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}

static UEVR_PluginInitializeParam* g_plugin_param = nullptr;

/* Lua binding functions */
namespace plugin {
namespace vr {

float get_world_scale() {
    if (g_plugin_param && g_plugin_param->vr) {
        return g_plugin_param->vr->get_world_scale();
    }
    return 1.0f;
}

void set_world_scale(float scale) {
    if (g_plugin_param && g_plugin_param->vr) {
        g_plugin_param->vr->set_world_scale(scale);
    }
}

float get_ui_offset_x() {
    if (g_plugin_param && g_plugin_param->vr) {
        return g_plugin_param->vr->get_ui_offset_x();
    }
    return 0.0f;
}

void set_ui_offset_x(float value) {
    if (g_plugin_param && g_plugin_param->vr) {
        g_plugin_param->vr->set_ui_offset_x(value);
    }
}

float get_ui_offset_y() {
    if (g_plugin_param && g_plugin_param->vr) {
        return g_plugin_param->vr->get_ui_offset_y();
    }
    return 0.0f;
}

void set_ui_offset_y(float value) {
    if (g_plugin_param && g_plugin_param->vr) {
        g_plugin_param->vr->set_ui_offset_y(value);
    }
}

float get_ui_offset_distance() {
    if (g_plugin_param && g_plugin_param->vr) {
        return g_plugin_param->vr->get_ui_offset_distance();
    }
    return 0.0f;
}

void set_ui_offset_distance(float value) {
    if (g_plugin_param && g_plugin_param->vr) {
        g_plugin_param->vr->set_ui_offset_distance(value);
    }
}

float get_ui_size() {
    if (g_plugin_param && g_plugin_param->vr) {
        return g_plugin_param->vr->get_ui_size();
    }
    return 0.0f;
}

void set_ui_size(float value) {
    if (g_plugin_param && g_plugin_param->vr) {
        g_plugin_param->vr->set_ui_size(value);
    }
}

bool get_ui_follows_view() {
    if (g_plugin_param && g_plugin_param->vr) {
        return g_plugin_param->vr->get_ui_follows_view();
    }
    return false;
}

void set_ui_follows_view(bool value) {
    if (g_plugin_param && g_plugin_param->vr) {
        g_plugin_param->vr->set_ui_follows_view(value);
    }
}

int get_ui_overlay_type() {
    if (g_plugin_param && g_plugin_param->vr) {
        return g_plugin_param->vr->get_ui_overlay_type();
    }
    return 0;
}

void set_ui_overlay_type(int value) {
    if (g_plugin_param && g_plugin_param->vr) {
        g_plugin_param->vr->set_ui_overlay_type(value);
    }
}

float get_ui_yaw() {
    if (g_plugin_param && g_plugin_param->vr) {
        return g_plugin_param->vr->get_ui_yaw();
    }
    return 0.0f;
}

void set_ui_yaw(float value) {
    if (g_plugin_param && g_plugin_param->vr) {
        g_plugin_param->vr->set_ui_yaw(value);
    }
}

float get_ui_roll() {
    if (g_plugin_param && g_plugin_param->vr) {
        return g_plugin_param->vr->get_ui_roll();
    }
    return 0.0f;
}

void set_ui_roll(float value) {
    if (g_plugin_param && g_plugin_param->vr) {
        g_plugin_param->vr->set_ui_roll(value);
    }
}

float get_ui_pitch() {
    if (g_plugin_param && g_plugin_param->vr) {
        return g_plugin_param->vr->get_ui_pitch();
    }
    return 0.0f;
}

void set_ui_pitch(float value) {
    if (g_plugin_param && g_plugin_param->vr) {
        g_plugin_param->vr->set_ui_pitch(value);
    }
}

float get_ui_cylinder_angle() {
    if (g_plugin_param && g_plugin_param->vr) {
        return g_plugin_param->vr->get_ui_cylinder_angle();
    }
    return 90.0f;
}

void set_ui_cylinder_angle(float value) {
    if (g_plugin_param && g_plugin_param->vr) {
        g_plugin_param->vr->set_ui_cylinder_angle(value);
    }
}

} // namespace vr
} // namespace plugin

/* Lua binding registration - adds overlay functions to vr table */
extern "C" __declspec(dllexport) void add_vr_overlay_bindings(void* lua_state) {
    if (lua_state == nullptr) {
        return;
    }

    auto L = (lua_State*)lua_state;
    
    // Get or create vr table
    lua_getglobal(L, "vr");
    if (lua_isnil(L, -1)) {
        lua_pop(L, 1);
        lua_newtable(L);
    }
    
    // Add world scale functions
    lua_pushcfunction(L, (lua_CFunction)plugin::vr::get_world_scale);
    lua_setfield(L, -2, "get_world_scale");
    
    lua_pushcfunction(L, (lua_CFunction)plugin::vr::set_world_scale);
    lua_setfield(L, -2, "set_world_scale");
    
    // Add overlay functions
    lua_pushcfunction(L, (lua_CFunction)plugin::vr::get_ui_offset_x);
    lua_setfield(L, -2, "get_ui_offset_x");
    
    lua_pushcfunction(L, (lua_CFunction)plugin::vr::set_ui_offset_x);
    lua_setfield(L, -2, "set_ui_offset_x");
    
    lua_pushcfunction(L, (lua_CFunction)plugin::vr::get_ui_offset_y);
    lua_setfield(L, -2, "get_ui_offset_y");
    
    lua_pushcfunction(L, (lua_CFunction)plugin::vr::set_ui_offset_y);
    lua_setfield(L, -2, "set_ui_offset_y");
    
    lua_pushcfunction(L, (lua_CFunction)plugin::vr::get_ui_offset_distance);
    lua_setfield(L, -2, "get_ui_offset_distance");
    
    lua_pushcfunction(L, (lua_CFunction)plugin::vr::set_ui_offset_distance);
    lua_setfield(L, -2, "set_ui_offset_distance");
    
    lua_pushcfunction(L, (lua_CFunction)plugin::vr::get_ui_size);
    lua_setfield(L, -2, "get_ui_size");
    
    lua_pushcfunction(L, (lua_CFunction)plugin::vr::set_ui_size);
    lua_setfield(L, -2, "set_ui_size");
    
    lua_pushcfunction(L, (lua_CFunction)plugin::vr::get_ui_follows_view);
    lua_setfield(L, -2, "get_ui_follows_view");
    
    lua_pushcfunction(L, (lua_CFunction)plugin::vr::set_ui_follows_view);
    lua_setfield(L, -2, "set_ui_follows_view");
    
    lua_pushcfunction(L, (lua_CFunction)plugin::vr::get_ui_overlay_type);
    lua_setfield(L, -2, "get_ui_overlay_type");
    
    lua_pushcfunction(L, (lua_CFunction)plugin::vr::set_ui_overlay_type);
    lua_setfield(L, -2, "set_ui_overlay_type");
    
    lua_pushcfunction(L, (lua_CFunction)plugin::vr::get_ui_yaw);
    lua_setfield(L, -2, "get_ui_yaw");
    
    lua_pushcfunction(L, (lua_CFunction)plugin::vr::set_ui_yaw);
    lua_setfield(L, -2, "set_ui_yaw");
    
    lua_pushcfunction(L, (lua_CFunction)plugin::vr::get_ui_roll);
    lua_setfield(L, -2, "get_ui_roll");
    
    lua_pushcfunction(L, (lua_CFunction)plugin::vr::set_ui_roll);
    lua_setfield(L, -2, "set_ui_roll");
    
    lua_pushcfunction(L, (lua_CFunction)plugin::vr::get_ui_pitch);
    lua_setfield(L, -2, "get_ui_pitch");
    
    lua_pushcfunction(L, (lua_CFunction)plugin::vr::set_ui_pitch);
    lua_setfield(L, -2, "set_ui_pitch");
    
    lua_pushcfunction(L, (lua_CFunction)plugin::vr::get_ui_cylinder_angle);
    lua_setfield(L, -2, "get_ui_cylinder_angle");
    
    lua_pushcfunction(L, (lua_CFunction)plugin::vr::set_ui_cylinder_angle);
    lua_setfield(L, -2, "set_ui_cylinder_angle");
    
    // Set global vr table
    lua_setglobal(L, "vr");
}

/* Plugin initialization */
extern "C" __declspec(dllexport) bool uevr_plugin_initialize(UEVR_PluginInitializeParam* param) {
    if (param == nullptr || param->version == nullptr) {
        return false;
    }

    // Check version compatibility
    if (param->version->major != UEVR_PLUGIN_VERSION_MAJOR ||
        param->version->minor < UEVR_PLUGIN_VERSION_MINOR) {
        return false;
    }

    g_plugin_param = param;

    // Log initialization
    if (param->functions && param->functions->log_info) {
        param->functions->log_info("MK12 Camera Plugin initialized");
    }

    // Register Lua bindings if Lua is available
    if (param->lua && param->lua->get_lua_state) {
        auto L = param->lua->get_lua_state();
        if (L) {
            add_vr_overlay_bindings(L);
            if (param->functions && param->functions->log_info) {
                param->functions->log_info("MK12 Camera Plugin: Lua bindings registered");
            }
        }
    }

    return true;
}

/* Plugin version */
extern "C" __declspec(dllexport) void uevr_plugin_required_version(UEVR_PluginVersion* version) {
    if (version) {
        version->major = UEVR_PLUGIN_VERSION_MAJOR;
        version->minor = UEVR_PLUGIN_VERSION_MINOR;
        version->patch = UEVR_PLUGIN_VERSION_PATCH;
    }
}

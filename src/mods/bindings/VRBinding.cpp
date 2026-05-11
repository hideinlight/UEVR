/*
This license governs this file (VRBinding.cpp), and is separate from the license for the rest of the UEVR codebase.

The MIT License

Copyright (c) 2023-2025 praydog

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include "../VR.hpp"
#include "../LuaLoader.hpp"

#include "VRBinding.hpp"

namespace api::vr {

float get_world_scale() {
    auto& vr = VR::get();
    if (vr) {
        return vr->get_world_scale();
    }
    return 1.0f;
}

void set_world_scale(float scale) {
    auto& vr = VR::get();
    if (vr) {
        vr->set_world_scale(scale);
    }
}

float get_ui_offset_x() {
    auto& vr = VR::get();
    if (vr) {
        return vr->get_overlay_component().get_ui_offset_x();
    }
    return 0.0f;
}

void set_ui_offset_x(float value) {
    auto& vr = VR::get();
    if (vr) {
        vr->get_overlay_component().set_ui_offset_x(value);
    }
}

float get_ui_offset_y() {
    auto& vr = VR::get();
    if (vr) {
        return vr->get_overlay_component().get_ui_offset_y();
    }
    return 0.0f;
}

void set_ui_offset_y(float value) {
    auto& vr = VR::get();
    if (vr) {
        vr->get_overlay_component().set_ui_offset_y(value);
    }
}

float get_ui_offset_distance() {
    auto& vr = VR::get();
    if (vr) {
        return vr->get_overlay_component().get_ui_offset_distance();
    }
    return 0.0f;
}

void set_ui_offset_distance(float value) {
    auto& vr = VR::get();
    if (vr) {
        vr->get_overlay_component().set_ui_offset_distance(value);
    }
}

float get_ui_size() {
    auto& vr = VR::get();
    if (vr) {
        return vr->get_overlay_component().get_ui_size();
    }
    return 0.0f;
}

void set_ui_size(float value) {
    auto& vr = VR::get();
    if (vr) {
        vr->get_overlay_component().set_ui_size(value);
    }
}

bool get_ui_follows_view() {
    auto& vr = VR::get();
    if (vr) {
        return vr->get_overlay_component().get_ui_follows_view();
    }
    return false;
}

void set_ui_follows_view(bool value) {
    auto& vr = VR::get();
    if (vr) {
        vr->get_overlay_component().set_ui_follows_view(value);
    }
}

int get_ui_overlay_type() {
    auto& vr = VR::get();
    if (vr) {
        return vr->get_overlay_component().get_ui_overlay_type();
    }
    return 0;
}

void set_ui_overlay_type(int value) {
    auto& vr = VR::get();
    if (vr) {
        vr->get_overlay_component().set_ui_overlay_type(value);
    }
}

float get_ui_yaw() {
    auto& vr = VR::get();
    if (vr) {
        return vr->get_overlay_component().get_ui_yaw();
    }
    return 0.0f;
}

void set_ui_yaw(float value) {
    auto& vr = VR::get();
    if (vr) {
        vr->get_overlay_component().set_ui_yaw(value);
    }
}

float get_ui_roll() {
    auto& vr = VR::get();
    if (vr) {
        return vr->get_overlay_component().get_ui_roll();
    }
    return 0.0f;
}

void set_ui_roll(float value) {
    auto& vr = VR::get();
    if (vr) {
        vr->get_overlay_component().set_ui_roll(value);
    }
}

float get_ui_pitch() {
    auto& vr = VR::get();
    if (vr) {
        return vr->get_overlay_component().get_ui_pitch();
    }
    return 0.0f;
}

void set_ui_pitch(float value) {
    auto& vr = VR::get();
    if (vr) {
        vr->get_overlay_component().set_ui_pitch(value);
    }
}

float get_ui_cylinder_angle() {
    auto& vr = VR::get();
    if (vr) {
        return vr->get_overlay_component().get_ui_cylinder_angle();
    }
    return 90.0f;
}

void set_ui_cylinder_angle(float value) {
    auto& vr = VR::get();
    if (vr) {
        vr->get_overlay_component().set_ui_cylinder_angle(value);
    }
}

bool is_decoupled_pitch_enabled() {
    auto& vr = VR::get();
    if (vr) {
        return vr->is_decoupled_pitch_enabled();
    }
    return false;
}

void set_decoupled_pitch_enabled(bool enabled) {
    auto& vr = VR::get();
    if (vr) {
        vr->set_decoupled_pitch(enabled);
    }
}

bool is_roomscale_enabled() {
    auto& vr = VR::get();
    if (vr) {
        return vr->is_roomscale_enabled();
    }
    return false;
}

void set_roomscale_enabled(bool enabled) {
    auto& vr = VR::get();
    if (vr) {
        vr->set_roomscale_enabled(enabled);
    }
}

bool is_roomscale_sweep_enabled() {
    auto& vr = VR::get();
    if (vr) {
        return vr->is_roomscale_sweep_enabled();
    }
    return false;
}

void set_roomscale_sweep_enabled(bool enabled) {
    auto& vr = VR::get();
    if (vr) {
        vr->set_roomscale_sweep_enabled(enabled);
    }
}

} // namespace api::vr

void bindings::open_vr(sol::state_view& lua) {
    auto vr = lua.create_table();

    vr["get_world_scale"] = api::vr::get_world_scale;
    vr["set_world_scale"] = api::vr::set_world_scale;
    vr["get_ui_offset_x"] = api::vr::get_ui_offset_x;
    vr["set_ui_offset_x"] = api::vr::set_ui_offset_x;
    vr["get_ui_offset_y"] = api::vr::get_ui_offset_y;
    vr["set_ui_offset_y"] = api::vr::set_ui_offset_y;
    vr["get_ui_offset_distance"] = api::vr::get_ui_offset_distance;
    vr["set_ui_offset_distance"] = api::vr::set_ui_offset_distance;
    vr["get_ui_size"] = api::vr::get_ui_size;
    vr["set_ui_size"] = api::vr::set_ui_size;
    vr["get_ui_follows_view"] = api::vr::get_ui_follows_view;
    vr["set_ui_follows_view"] = api::vr::set_ui_follows_view;
    vr["get_ui_overlay_type"] = api::vr::get_ui_overlay_type;
    vr["set_ui_overlay_type"] = api::vr::set_ui_overlay_type;
    vr["get_ui_yaw"] = api::vr::get_ui_yaw;
    vr["set_ui_yaw"] = api::vr::set_ui_yaw;
    vr["get_ui_roll"] = api::vr::get_ui_roll;
    vr["set_ui_roll"] = api::vr::set_ui_roll;
    vr["get_ui_pitch"] = api::vr::get_ui_pitch;
    vr["set_ui_pitch"] = api::vr::set_ui_pitch;
    vr["get_ui_cylinder_angle"] = api::vr::get_ui_cylinder_angle;
    vr["set_ui_cylinder_angle"] = api::vr::set_ui_cylinder_angle;
    vr["is_decoupled_pitch_enabled"] = api::vr::is_decoupled_pitch_enabled;
    vr["set_decoupled_pitch_enabled"] = api::vr::set_decoupled_pitch_enabled;
    vr["is_roomscale_enabled"] = api::vr::is_roomscale_enabled;
    vr["set_roomscale_enabled"] = api::vr::set_roomscale_enabled;
    vr["is_roomscale_sweep_enabled"] = api::vr::is_roomscale_sweep_enabled;
    vr["set_roomscale_sweep_enabled"] = api::vr::set_roomscale_sweep_enabled;

    lua["vr"] = vr;
}

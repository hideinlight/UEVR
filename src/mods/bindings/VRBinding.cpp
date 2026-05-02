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

} // namespace api::vr

void bindings::open_vr(sol::state_view& lua) {
    auto vr = lua.create_table();

    vr["get_world_scale"] = api::vr::get_world_scale;
    vr["set_world_scale"] = api::vr::set_world_scale;

    lua["vr"] = vr;
}

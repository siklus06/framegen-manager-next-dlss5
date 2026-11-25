#pragma once
#include <cstdint>

namespace framegen_manager_next_dlss5 {
inline constexpr const char* kModuleName = "framegen-manager-next-dlss5";
inline constexpr const char* kBuildSalt = "d1f12abc81935ae2";
struct RuntimeConfig {
    uint32_t target_fps = 144;
    float fov_radius = 65.0f;
    float smooth_factor = 1.45f;
    bool draw_bounds = true;
};
} // namespace framegen_manager_next_dlss5

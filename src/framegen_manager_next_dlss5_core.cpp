#include "../include/framegen_manager_next_dlss5_runtime.hpp"
#include <windows.h>
#include <atomic>

namespace framegen_manager_next_dlss5 {
static std::atomic<bool> g_running{true};
void PollHotkeys(bool& menu_open) noexcept {
    if (GetAsyncKeyState(VK_INSERT) & 1) menu_open = !menu_open;
    if (GetAsyncKeyState(VK_END) & 1) g_running.store(false, std::memory_order_relaxed);
}
} // namespace framegen_manager_next_dlss5

int main() {
    bool menu_open = true;
    while (framegen_manager_next_dlss5::g_running.load(std::memory_order_relaxed)) {
        framegen_manager_next_dlss5::PollHotkeys(menu_open);
        Sleep(6);
    }
    return 0;
}

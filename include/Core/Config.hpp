#pragma once

namespace Core {

    constexpr int kWindowWidth = 1280;
    constexpr int kWindowHeight = 768;
    constexpr char kWindowTitle[] = "One_Boom";

    constexpr int INPUT_LOCK_FRAME = 30;

    enum MouseCursor {
        HIDE_MOUSE = 0,
        SHOW_MOUSE = 1,
    };

    enum MouseButton {
        LEFT_BUTTON = 0,
        RIGHT_BUTTON = 1,
        MIDDLE_BUTTON = 2,
    };

} // namespace Core

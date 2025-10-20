#pragma once

namespace Core {

    // 393×852
    constexpr int kWindowWidth = 480;
    constexpr int kWindowHeight = 720;
    constexpr char kWindowTitle[] = "One_Boom";

    constexpr int INPUT_LOCK_FRAME = 30;
    constexpr int COUNT_TIME = (3 * 60);

    enum MouseCursor {
        HIDE_MOUSE = 0,
        SHOW_MOUSE = 1,
    };

    enum MouseButton {
        LEFT_BUTTON = 0,
        RIGHT_BUTTON = 1,
        MIDDLE_BUTTON = 2,
    };

    // シーンの状態を表す列挙型
    enum class SceneState {
        MAIN,
        GAMEPLAY,
        PAUSE,
        GAMEOVER_WIN,
        GAMEOVER_LOSE,
    };

} // namespace Core

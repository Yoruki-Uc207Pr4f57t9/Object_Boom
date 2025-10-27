#pragma once

namespace Core {

    // 393×852
    constexpr int kWindowWidth = 480;
    constexpr int kWindowHeight = 720;
    constexpr char kWindowTitle[] = "タイムリミット：残された選択";

    constexpr int INPUT_LOCK_FRAME = 30;
    constexpr int COUNT_TIME = (3 * 60);

    constexpr double PI = 3.14159265358979323846;
    constexpr int PLAYER_M_LIVES = 4;  // プレイヤーの初期バッテリー数 (4枚絵)
    constexpr int PLAYER_M_MISSION = 3;

    constexpr int PW_ROW = 3;
    constexpr int PW_CELL = 5;


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
        PAUSE,
        TEXT,
        GAMEPLAY,
        GAMEOVER_WIN,
        GAMEOVER_LOSE,
        GAMEOVER_HIDE,
        RESET
    };

    enum RLModel : int {
        LEFT,
        RIGHT
    };

} // namespace Core

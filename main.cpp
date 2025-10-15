#include <Novice.h>
#include "Core/Config.hpp"
// TEST
#include "Component/Timers.hpp"
#include "Game/GameSession.hpp"
#include "Game/GameManager.hpp"



// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

    // ライブラリの初期化
    Novice::Initialize(Core::kWindowTitle, Core::kWindowWidth, Core::kWindowHeight);

    Game::GameSession session;
    Game::GameManager* gameMgr = new Game::GameManager(&session);

    gameMgr->InitResources();
    gameMgr->InitManager();

    // ウィンドウの×ボタンが押されるまでループ
    while (Novice::ProcessMessage() == 0  && !session.GetGameSetting()->IsGameOver()) {
        // フレームの開始
        Novice::BeginFrame();
        session.GetKeyBoard()->PollKeyboard(*session.GetKeyBoard(), *session.GetGameSetting());

        gameMgr->OnInput();

        gameMgr->Update();

        gameMgr->Render();

        // フレームの終了
        Novice::EndFrame();
    }

    // ライブラリの終了
    Novice::Finalize();
    return 0;
}



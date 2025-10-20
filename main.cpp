#include <Novice.h>
#include "Core/Config.hpp"
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
    while (Novice::ProcessMessage() == 0 && !session.GetGameSetting()->IsGameOver()) {
        // フレームの開始
        Novice::BeginFrame();

        gameMgr->OnInput();

        gameMgr->Update();

        gameMgr->Render();

        session.GetGameSetting()->IncrementFrame();
        // フレームの終了
        Novice::EndFrame();
    }

    // ライブラリの終了
    Novice::Finalize();
    return 0;
}



#include "Game/GameManager.hpp"

namespace Game {

    // リソースの初期化
    void GameManager::InitResources() {
        session_->GetResources()->LoadAll();
    }

    // マネージャーの初期化
    void GameManager::InitManager() {
        boomAct_->Init();
        secretBoardAct_->Init();
        guiAct_->Init();
    }

    // 入力処理
    void GameManager::OnInput() {
        session_->GetKeyBoard()->PollKeyboard(*session_->GetKeyBoard(), *session_->GetGameSetting());
        secretBoardAct_->Input(*session_->GetKeyBoard(), *session_->GetMouse());
    }

    // 更新処理
    void GameManager::Update() {
        //if (session_->GetCurrentState() != Core::SceneState::GAMEPLAY) return;

        boomAct_->Update();
        secretBoardAct_->Update();
        guiAct_->Update();

        if (session_->GetPlayerData()->batteryCount == 0) {
            Novice::ScreenPrintf(100, 50, "Game Over");
        }
    }

    // 描画処理
    void GameManager::Render() {
        boomAct_->Render();
        secretBoardAct_->Render();
        guiAct_->Render();

    }

    // 終了処理
    void GameManager::Shutdown() {
        boomAct_->Shutdown();
        secretBoardAct_->Shutdown();
        guiAct_->Shutdown();
    }
}


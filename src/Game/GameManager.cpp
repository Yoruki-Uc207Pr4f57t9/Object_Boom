#include "Game/GameManager.hpp"

namespace Game {

    // リソースの初期化
    void GameManager::InitResources() {
        session_->GetResources()->LoadAll();
    }

    // マネージャーの初期化
    void GameManager::InitManager() {
        mainAct_->Init();

        boomAct_->Init();
        secretBoardAct_->Init();
        guiAct_->Init();

        winAct_->Init();
        loseAct_->Init();
        hideAct_->Init();


    }

    // 入力処理
    void GameManager::OnInput() {
        session_->GetKeyBoard()->PollKeyboard(*session_->GetKeyBoard(), *session_->GetGameSetting());
        if (session_->GetCurrentState() == Core::SceneState::MAIN) {
            mainAct_->Input(*session_->GetKeyBoard(), *session_->GetMouse());
        } else if (session_->GetCurrentState() == Core::SceneState::GAMEPLAY) {
            secretBoardAct_->Input(*session_->GetKeyBoard(), *session_->GetMouse());
        } else if (session_->GetCurrentState() == Core::SceneState::GAMEOVER_WIN) {

        } else if (session_->GetCurrentState() == Core::SceneState::GAMEOVER_LOSE) {

        } else if (session_->GetCurrentState() == Core::SceneState::GAMEOVER_HIDE) {
            hideAct_->Input(*session_->GetKeyBoard(), *session_->GetMouse());
        }

    }

    // 更新処理
    void GameManager::Update() {
        // return;
        if (session_->GetCurrentState() == Core::SceneState::MAIN) {
            mainAct_->Update();
            guiAct_->Update();
        } else if (session_->GetCurrentState() == Core::SceneState::GAMEPLAY) {
            boomAct_->Update();
            secretBoardAct_->Update();
            guiAct_->Update();

            if (session_->GetPlayerData()->batteryCount == 0 || boomAct_->GetCountdownTimer().IsFinished()) {
                Novice::ScreenPrintf(100, 50, "Game Over");
            }
        } else if (session_->GetCurrentState() == Core::SceneState::GAMEOVER_WIN) {

        } else if (session_->GetCurrentState() == Core::SceneState::GAMEOVER_LOSE) {

        } else if (session_->GetCurrentState() == Core::SceneState::GAMEOVER_HIDE) {
            hideAct_->Update();
        }

       
    }

    // 描画処理
    void GameManager::Render() {
        if (session_->GetCurrentState() == Core::SceneState::MAIN) {
            mainAct_->Render();
            guiAct_->Render();
        } else if (session_->GetCurrentState() == Core::SceneState::GAMEPLAY) {
            boomAct_->Render();
            secretBoardAct_->Render();
            guiAct_->Render();
        } else if (session_->GetCurrentState() == Core::SceneState::GAMEOVER_WIN) {
            winAct_->Render();
        } else if (session_->GetCurrentState() == Core::SceneState::GAMEOVER_LOSE) {
            loseAct_->Render();
        } else if (session_->GetCurrentState() == Core::SceneState::GAMEOVER_HIDE) {
            hideAct_->Render();
        }
        

    }

    // 終了処理
    void GameManager::Shutdown() {
        boomAct_->Shutdown();
        secretBoardAct_->Shutdown();
        guiAct_->Shutdown();
    }
}


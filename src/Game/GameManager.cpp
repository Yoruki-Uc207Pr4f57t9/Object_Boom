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

        loadingAct_->Init();
        playTextAct_->Init();


    }

    // 入力処理
    void GameManager::OnInput() {
        session_->GetKeyBoard()->PollKeyboard(*session_->GetKeyBoard(), *session_->GetGameSetting());
        if (session_->GetCurrentState() == Core::SceneState::MAIN) {
            mainAct_->Input(*session_->GetKeyBoard(), *session_->GetMouse());
        } if (session_->GetCurrentState() == Core::SceneState::TEXT) {
            playTextAct_->Input(*session_->GetKeyBoard(), *session_->GetMouse());
        } else if (session_->GetCurrentState() == Core::SceneState::GAMEPLAY) {
            secretBoardAct_->Input(*session_->GetKeyBoard(), *session_->GetMouse());
        } else if (session_->GetCurrentState() == Core::SceneState::GAMEOVER_WIN) {
            winAct_->Input(*session_->GetKeyBoard(), *session_->GetMouse());
        } else if (session_->GetCurrentState() == Core::SceneState::GAMEOVER_LOSE) {
            loseAct_->Input(*session_->GetKeyBoard(), *session_->GetMouse());
        } else if (session_->GetCurrentState() == Core::SceneState::GAMEOVER_HIDE) {
            hideAct_->Input(*session_->GetKeyBoard(), *session_->GetMouse());
        }

    }

    // 更新処理
    void GameManager::Update() {
        if (session_->GetLoading()) {
            if (session_->GetGameSetting()->GetCurrentFrame() % (1 * 60) == 0) {
                session_->SetLoading(false);
            }
            loadingAct_->Update();
        } else if (session_->GetCurrentState() == Core::SceneState::MAIN) {
            mainAct_->Update();
            guiAct_->Update();
        } else if (session_->GetCurrentState() == Core::SceneState::GAMEPLAY || session_->GetCurrentState() == Core::SceneState::TEXT) {
            playTextAct_->Update();
            boomAct_->Update();
            secretBoardAct_->Update();
            guiAct_->Update();

            if (session_->GetPlayerData()->batteryCount == 0 || boomAct_->GetCountdownTimer().IsFinished()) {
                session_->SetCurrentState(Core::SceneState::GAMEOVER_LOSE);
            } else if (session_->GetPlayerData()->missionCount == 0) {
                session_->SetCurrentState(Core::SceneState::GAMEOVER_WIN);
            }
        } else if (session_->GetCurrentState() == Core::SceneState::GAMEOVER_WIN) {
            winAct_->Update();
        } else if (session_->GetCurrentState() == Core::SceneState::GAMEOVER_LOSE) {
            loseAct_->Update();
        } else if (session_->GetCurrentState() == Core::SceneState::GAMEOVER_HIDE) {
            hideAct_->Update();
        } else {
            Reset();
            session_->SetCurrentState(Core::SceneState::MAIN);
        }

       
    }

    // 描画処理
    void GameManager::Render() {
        if (session_->GetLoading()){
            loadingAct_->Render();
            guiAct_->Render();
        } else if (session_->GetCurrentState() == Core::SceneState::MAIN) {
            mainAct_->Render();
            guiAct_->Render();
        } else if (session_->GetCurrentState() == Core::SceneState::GAMEPLAY || session_->GetCurrentState() == Core::SceneState::TEXT) {
            secretBoardAct_->Render();
            boomAct_->Render();
            guiAct_->Render();
            playTextAct_->Render();
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
        /*boomAct_->Shutdown();
        secretBoardAct_->Shutdown();
        guiAct_->Shutdown();*/
    }

    void GameManager::Reset() {
        session_->GetPlayerData()->batteryCount = Core::PLAYER_M_LIVES;
        session_->GetPlayerData()->missionCount = Core::PLAYER_M_MISSION;
        winAct_->Shutdown();
        loseAct_->Shutdown();
    }
}


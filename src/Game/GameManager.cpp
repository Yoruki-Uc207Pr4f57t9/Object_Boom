#include "Game/GameManager.hpp"

namespace Game {

    // リソースの初期化
    void GameManager::InitResources(Core::ResourceManager* rm) {
        rm->LoadAll();
    }

    // マネージャーの初期化
    void GameManager::InitManager() {
        boomAct_->Init();

    }

    // 入力処理
    void GameManager::OnInput() {
        

    }

    // 更新処理
    void GameManager::Update() {

        session_->GetMouse()->Update();
        if (session_->GetCurrentState() != Core::SceneState::GAMEPLAY) return;

        boomAct_->Update();



    }

    // 描画処理
    void GameManager::Render() {
        boomAct_->Render();

    }

    // 終了処理
    void GameManager::Shutdown() {
        boomAct_->Shutdown();
        secretBoardAct_->Shutdown();
    }
}


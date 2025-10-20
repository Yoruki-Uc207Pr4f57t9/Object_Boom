#include "Game/GameManager.hpp"

namespace Game {

    // リソースの初期化
    void GameManager::InitResources() {
        session_->GetResources()->LoadAll();
        bgImage_ = Component::ImageSpan({ 0, 0 }, session_->GetResources()->MobileBGHandle());
        evilIconImage_ = Component::ImageSpan({ 95.f, 50.f },
            session_->GetResources()->EvilIconHandle());

        area_ = GameArea{
            { 85, 45 },
            { 300, 470 }
        };
    }

    // マネージャーの初期化
    void GameManager::InitManager() {
        boomAct_->Init();
        secretBoardAct_->Init();
    }

    // 入力処理
    void GameManager::OnInput() {
        session_->GetKeyBoard()->PollKeyboard(*session_->GetKeyBoard(), *session_->GetGameSetting());

        
        secretBoardAct_->Input(*session_->GetKeyBoard(), *session_->GetMouse());
    }

    // 更新処理
    void GameManager::Update() {

        session_->GetMouse()->Update();
        //if (session_->GetCurrentState() != Core::SceneState::GAMEPLAY) return;

        boomAct_->Update();
        secretBoardAct_->Update();
    }

    // 描画処理
    void GameManager::Render() {
        boomAct_->Render();
        secretBoardAct_->Render();
        bgImage_.Render();
        evilIconImage_.Render();

        // debug
        Novice::DrawBox(
            (int)area_.position.x,
            (int)area_.position.y,
            (int)area_.size.x,
            (int)area_.size.y,
            0,
            RED,
            kFillModeWireFrame
        );
    }

    // 終了処理
    void GameManager::Shutdown() {
        boomAct_->Shutdown();
        secretBoardAct_->Shutdown();
    }
}


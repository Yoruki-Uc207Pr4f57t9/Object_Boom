#include "Game/IGOHideAction.hpp"
#include <Novice.h>

namespace Game {
    void IGOHideAction::Init() {
        hideText_ = Component::TextSpan({ 0, 0 }, "", session_->GetResources()->GoHideTextHandle());
        int w = (int)(hideText_.GetSize().x / 2);
        int h = (int)(hideText_.GetSize().y / 2);
        hideText_.SetPosition({ (float)(Core::kWindowWidth / 2 - w), (float)(Core::kWindowHeight / 2 - h / 2) });

    }
    void IGOHideAction::Input(KeyBoard& kb, Mouse& mouse) {
        mouse;
        if (!session_->DetectInputLock() && kb.keys[DIK_SPACE] == 0 && kb.preKeys[DIK_SPACE] != 0) {
            session_->ResetInputLock();
            session_->GetGameSetting()->SetGameOver(true);
        }
    }
    void IGOHideAction::Update() {
        if (session_->GetGameSetting()->GetCurrentFrame() % (switchTime_ * 60) == 0) {
            session_->GetGameSetting()->SetGameOver(true);
        }

    }
    void IGOHideAction::Render() {
        Novice::DrawBox(0, 0, Core::kWindowWidth, Core::kWindowHeight, 0, WHITE, kFillModeSolid);
        
        hideText_.Render();

    }
    void IGOHideAction::Shutdown() {

    }
}


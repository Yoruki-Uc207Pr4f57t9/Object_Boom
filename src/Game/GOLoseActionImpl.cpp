#include "Game/IGOLoseAction.hpp"
#include <Novice.h>

namespace Game {
    void IGOLoseAction::Init() {
        loseTL01_ = Component::TextSpan({ 0, 0 } , "", session_->GetResources()->GoLoseTL01TextHandle());
        loseTL02_ = Component::TextSpan({ 0, 0 } , "", session_->GetResources()->GoLoseTL02TextHandle());
        loseTL03_ = session_->GetResources()->GoLoseTL03ImageHandle();

    }
    void IGOLoseAction::Input(KeyBoard& kb, Mouse& mouse) {
        mouse;
        if (kb.keys[DIK_SPACE] == 0 && kb.preKeys[DIK_SPACE] != 0 && session_->DetectInputLock()) {
            textCount_++;
            session_->ResetInputLock();
        }
    }
    void IGOLoseAction::Update() {
        /*if (session_->GetGameSetting()->GetCurrentFrame() % (switchTime_ * 60) == 0) {
            textCount_++;
        }*/
        if (textCount_ >= timeLineCount_) {
            session_->SetCurrentState(Core::SceneState::RESET);
        }

    }
    void IGOLoseAction::Render() {
        Novice::DrawBox(0, 0, Core::kWindowWidth, Core::kWindowHeight, 0, WHITE, kFillModeSolid);
        if (textCount_ == TEXTS::TEXT01) {
            int w = (int)(loseTL01_.GetSize().x / 2);
            int h = (int)(loseTL01_.GetSize().y / 2);
            loseTL01_.SetPosition({ (float)(Core::kWindowWidth / 2 - w ), (float)(Core::kWindowHeight / 2 - h / 2) });
            loseTL01_.Render();
        } else if (textCount_ == TEXTS::TEXT02) {
            int w = (int)(loseTL02_.GetSize().x / 2);
            int h = (int)(loseTL02_.GetSize().y / 2);
            loseTL02_.SetPosition({ (float)(Core::kWindowWidth / 2 - w ), (float)(Core::kWindowHeight / 2 - h / 2) });
            loseTL02_.Render();
        } else if (textCount_ == TEXTS::TEXT03) {
            int w = (int)(loseTL03_.resource.size.x * loseTL03_.resource.scale);
            int h = (int)(loseTL03_.resource.size.y * loseTL03_.resource.scale);
            Novice::DrawSpriteRect((int)(Core::kWindowWidth / 2 - w / 2), (int)(Core::kWindowHeight / 2 - h / 2), 0, 0, (int)loseTL03_.resource.size.x, (int)loseTL03_.resource.size.y,
                loseTL03_.resource.textureHandle, loseTL03_.resource.scale, loseTL03_.resource.scale, 0, WHITE);
        }

    }
    void IGOLoseAction::Shutdown() {

    }
}

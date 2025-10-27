#include "Game/IGOLoseAction.hpp"
#include <Novice.h>

namespace Game {
    void SetTextPosiByLose(Component::TextSpan& text) {
        int w = (int)(text.GetSize().x / 2);
        int h = (int)(text.GetSize().y / 2);
        text.SetPosition({ (float)(Core::kWindowWidth / 2 - w), (float)(Core::kWindowHeight / 2 - h / 2) });
    }
    void IGOLoseAction::Init() {
        loseTL01_ = Component::TextSpan({ 0, 0 } , "", session_->GetResources()->GoLoseTL01TextHandle());
        SetTextPosiByLose(loseTL01_);
        loseTL02_ = Component::TextSpan({ 0, 0 } , "", session_->GetResources()->GoLoseTL02TextHandle());
        SetTextPosiByLose(loseTL02_);
        loseTL03_ = session_->GetResources()->GoLoseTL03ImageHandle();

    }
    void IGOLoseAction::Input(KeyBoard& kb, Mouse& mouse) {
        mouse;
        if (!session_->DetectInputLock() && kb.keys[DIK_SPACE] == 0 && kb.preKeys[DIK_SPACE] != 0) {
            session_->ResetInputLock();
            textCount_++;
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
        if (textCount_ == LOSE_TEXTS::L_TEXT01) {
            loseTL01_.Render();
        } else if (textCount_ == LOSE_TEXTS::L_TEXT02) {
            loseTL02_.Render();
        } else if (textCount_ == LOSE_TEXTS::L_TEXT03) {
            int w = (int)(loseTL03_.resource.size.x * loseTL03_.resource.scale);
            int h = (int)(loseTL03_.resource.size.y * loseTL03_.resource.scale);
            Novice::DrawSpriteRect((int)(Core::kWindowWidth / 2 - w / 2), (int)(Core::kWindowHeight / 2 - h / 2), 0, 0, (int)loseTL03_.resource.size.x, (int)loseTL03_.resource.size.y,
                loseTL03_.resource.textureHandle, loseTL03_.resource.scale, loseTL03_.resource.scale, 0, WHITE);
        }

    }
    void IGOLoseAction::Shutdown() {
        textCount_ = LOSE_TEXTS::L_TEXT01;
    }
}

#include "Game/IGOWinAction.hpp"
#include <Novice.h>

namespace Game {

    
    void SetTextPosi(Component::TextSpan& text) {
        int w = (int)(text.GetSize().x / 2);
        int h = (int)(text.GetSize().y / 2);
        text.SetPosition({ (float)(Core::kWindowWidth / 2 - w), (float)(Core::kWindowHeight / 2 - h / 2) });
        
    }
    void IGOWinAction::Init() {
        winTL01_ = Component::TextSpan({ 0, 0 }, "", session_->GetResources()->GoWinTL01TextHandle());
        SetTextPosi(winTL01_);
        winTL02_ = Component::TextSpan({ 0, 0 }, "", session_->GetResources()->GoWinTL02TextHandle());
        SetTextPosi(winTL02_);
        winTL03_ = Component::TextSpan({ 0, 0 }, "", session_->GetResources()->GoWinTL03TextHandle());
        SetTextPosi(winTL03_);
        winTL04_ = Component::TextSpan({ 0, 0 }, "", session_->GetResources()->GoWinTL04TextHandle());
        SetTextPosi(winTL04_);
        winTL05_ = Component::TextSpan({ 0, 0 }, "", session_->GetResources()->GoWinTL05TextHandle());
        SetTextPosi(winTL05_);
        winTL06_ = Component::TextSpan({ 0, 0 }, "", session_->GetResources()->GoWinTL06TextHandle());
        SetTextPosi(winTL06_);
        winTL07_ = Component::TextSpan({ 0, 0 }, "", session_->GetResources()->GoWinTL07TextHandle());
        SetTextPosi(winTL07_);
        winTL08_ = Component::TextSpan({ 0, 0 }, "", session_->GetResources()->GoWinTL08TextHandle());
        SetTextPosi(winTL08_);

    }
    void IGOWinAction::Input(KeyBoard& kb, Mouse& mouse) {
        mouse;
        if (!session_->DetectInputLock() && kb.keys[DIK_SPACE] == 0 && kb.preKeys[DIK_SPACE] != 0) {
            session_->ResetInputLock();
            textCount_++;
        }
    }
    void IGOWinAction::Update() {
        if (textCount_ >= timeLineCount_) {
            session_->SetCurrentState(Core::SceneState::RESET);
        }

    }


    void IGOWinAction::Render() {
        Novice::DrawBox(0, 0, Core::kWindowWidth, Core::kWindowHeight, 0, WHITE, kFillModeSolid);
        if (textCount_ == WIN_TEXTS::W_TEXT01) {
            winTL01_.Render();
        } else if (textCount_ == WIN_TEXTS::W_TEXT02) {
            winTL02_.Render();
        } else if (textCount_ == WIN_TEXTS::W_TEXT03) {
            winTL03_.Render();
        } else if (textCount_ == WIN_TEXTS::W_TEXT04) {
            winTL04_.Render();
        } else if (textCount_ == WIN_TEXTS::W_TEXT05) {
            winTL05_.Render();
        } else if (textCount_ == WIN_TEXTS::W_TEXT06) {
            winTL06_.Render();
        } else if (textCount_ == WIN_TEXTS::W_TEXT07) {
            winTL07_.Render();
        } else if (textCount_ == WIN_TEXTS::W_TEXT08) {
            winTL08_.Render();
        }

    }
    void IGOWinAction::Shutdown() {
        textCount_ = WIN_TEXTS::W_TEXT01;
    }
}


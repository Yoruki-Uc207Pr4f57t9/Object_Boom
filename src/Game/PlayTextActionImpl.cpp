#include "Game/IPlayTextAction.hpp"
#include <Novice.h>

namespace Game {


    void IPlayTextAction::Init() {
        playTL01_ = Component::TextSpan({ 0, 0 }, "", session_->GetResources()->TL01PlayerText01Handle());
        playTL01_.SetPosition({ Core::kWindowWidth / 2 - playTL01_.GetSize().x / 2, 600 });
        playTL02_ = Component::TextSpan({ 0, 0 }, "", session_->GetResources()->TL02EvilText01Handle());
        playTL02_.SetPosition({ Core::kWindowWidth / 2 - 65 , 70 });
        playTL03_ = Component::TextSpan({ 0, 0 }, "", session_->GetResources()->TL03PlayerText02Handle());
        playTL03_.SetPosition({ Core::kWindowWidth / 2 - playTL03_.GetSize().x / 2, 600 });
        playTL04_ = Component::TextSpan({ 0, 0 }, "", session_->GetResources()->TL04EvilText02Handle());
        playTL04_.SetPosition({ Core::kWindowWidth / 2 - 65, 70 });
        playTL05_ = Component::TextSpan({ 0, 0 }, "", session_->GetResources()->TL05PlayerText03Handle());
        playTL05_.SetPosition({ Core::kWindowWidth / 2 - playTL05_.GetSize().x / 2, 600 });
        playTL06_ = Component::TextSpan({ 0, 0 }, "", session_->GetResources()->TL06EvilText03Handle());
        playTL06_.SetPosition({ Core::kWindowWidth / 2 - 65, 70 });
        playTL07_ = Component::TextSpan({ 0, 0 }, "", session_->GetResources()->TL07PlayerText04Handle());
        playTL07_.SetPosition({ Core::kWindowWidth / 2 - playTL07_.GetSize().x / 2, 600 });
        playTL08_ = Component::TextSpan({ 0, 0 }, "", session_->GetResources()->TL08EvilText04Handle());
        playTL08_.SetPosition({ Core::kWindowWidth / 2 - 65, 70 });
        playTL09_ = Component::TextSpan({ 0, 0 }, "", session_->GetResources()->TL09EvilText05Handle());
        playTL09_.SetPosition({ Core::kWindowWidth / 2 - 65, 70 });
        playTL10_ = Component::TextSpan({ 0, 0 }, "", session_->GetResources()->TL10PlayerText05Handle());
        playTL10_.SetPosition({ Core::kWindowWidth / 2 - playTL10_.GetSize().x / 2, 600 });
        playTL11_ = Component::TextSpan({ 0, 0 }, "", session_->GetResources()->TL11EvilText06Handle());
        playTL11_.SetPosition({ Core::kWindowWidth / 2 - 65, 70 });

    }
    void IPlayTextAction::Input(KeyBoard& kb, Mouse& mouse) {
        mouse;
        if (!session_->DetectInputLock() && kb.keys[DIK_SPACE] == 0 && kb.preKeys[DIK_SPACE] != 0) {
            session_->ResetInputLock();
            textCount_++;
        }
        
    }
    void IPlayTextAction::Update() {
        /*if (session_->GetGameSetting()->GetCurrentFrame() % (switchTime_ * 60) == 0) {
            textCount_++;
        }*/
        if (textCount_ >= timeLineCount_) {
            session_->SetCurrentState(Core::SceneState::GAMEPLAY);
        }

    }


    void IPlayTextAction::Render() {
        if (textCount_ == PLAY_TEXTS::P_TEXT01) {
            playTL01_.Render();
        } else if (textCount_ == PLAY_TEXTS::P_TEXT02) {
            playTL02_.Render();
        } else if (textCount_ == PLAY_TEXTS::P_TEXT03) {
            playTL03_.Render();
        } else if (textCount_ == PLAY_TEXTS::P_TEXT04) {
            playTL04_.Render();
        } else if (textCount_ == PLAY_TEXTS::P_TEXT05) {
            playTL05_.Render();
        } else if (textCount_ == PLAY_TEXTS::P_TEXT06) {
            playTL06_.Render();
        } else if (textCount_ == PLAY_TEXTS::P_TEXT07) {
            playTL07_.Render();
        } else if (textCount_ == PLAY_TEXTS::P_TEXT08) {
            playTL08_.Render();
        } else if (textCount_ == PLAY_TEXTS::P_TEXT09) {
            playTL09_.Render();
        } else if (textCount_ == PLAY_TEXTS::P_TEXT10) {
            playTL10_.Render();
        } else if (textCount_ == PLAY_TEXTS::P_TEXT11) {
            playTL11_.Render();
        }
        

    }
    void IPlayTextAction::Shutdown() {

        textCount_ = PLAY_TEXTS::P_TEXT01;
    }
}


                                                                     
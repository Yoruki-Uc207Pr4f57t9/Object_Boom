#include "Game/IMainAction.hpp"
#include <Novice.h>

namespace Game {
    void IMainAction::Init() {
        bgImage_ = Component::ImageSpan({ 0, 0 }, session_->GetResources()->MobileMainBGHandle());
        int iconWidth = (int)(session_->GetResources()->EvilIconComicHandle().resource.size.x * session_->GetResources()->EvilIconComicHandle().resource.scale);
        iconImage_ = Component::ImageSpan({ (float)(Core::kWindowWidth / 2 - iconWidth / 2) - 5, 75.f}, session_->GetResources()->EvilIconComicHandle());
        int nameWidth = (int)(session_->GetResources()->EvilIconTextHandle().resource.size.x * session_->GetResources()->EvilIconTextHandle().resource.scale);
        nameText_ = Component::TextSpan({ (float)(Core::kWindowWidth / 2 - nameWidth/ 2), 210.f },"Drak Game Master", session_->GetResources()->EvilIconTextHandle());

        flagImage_ = Component::ImageSpan({ (float)(flagSelect_[selectIndex_]), 400.f}, session_->GetResources()->MainFlagHandle());
    }
    void IMainAction::Input(KeyBoard& kb, Mouse& mouse) {
        mouse;
        if (kb.keys[DIK_SPACE] == 0 && kb.preKeys[DIK_SPACE] != 0) {
            if (selectIndex_ == Core::RLModel::RIGHT) {
                session_->SetCurrentState(Core::SceneState::GAMEPLAY);
            } else {
                session_->SetCurrentState(Core::SceneState::GAMEOVER_HIDE);
            }
        }
    }
    void IMainAction::Update() {
        if (session_->GetGameSetting()->GetCurrentFrame() % 60 == 0) {
            selectIndex_ = (selectIndex_ == Core::RLModel::LEFT ? Core::RLModel::RIGHT : Core::RLModel::LEFT);
            flagImage_.SetPosition({ (float)(flagSelect_[selectIndex_]), 400.f });
        }

    }
    void IMainAction::Render() {
        iconImage_.Render();
        bgImage_.Render();
        nameText_.Render();

        flagImage_.Render();

    }
    void IMainAction::Shutdown() {
    }
}



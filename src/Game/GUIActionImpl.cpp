#include "Game/IGUIAction.hpp"
#include <Novice.h>

namespace Game {
    void IGUIAction::Init() {
        bgImage_ = Component::ImageSpan({ 0, 0 }, session_->GetResources()->MobileBGHandle());
        evilIconImage_ = Component::ImageSpan({ 95.f, 70.f },
            session_->GetResources()->EvilIconHandle());

        

        area_ = GameArea{
            { 85, 45 },
            { 300, 470 }
        };
    }
    void IGUIAction::Input(KeyBoard& kb, Mouse& mouse) {
        kb;
        mouse;
    }
    void IGUIAction::Update() {
        powerMeter_ = session_->GetResources()->MobilePowerHandle(Core::PLAYER_M_LIVES - session_->GetPlayerData()->batteryCount);
        line_ = session_->GetResources()->LineHandle(Core::PLAYER_M_MISSION - session_->GetPlayerData()->missionCount);

    }
    void IGUIAction::Render() {
        bgImage_.Render();
        if (session_->GetLoading()) {
            
        } else if (session_->GetCurrentState() == Core::SceneState::MAIN) {
            
        } else if (session_->GetCurrentState() == Core::SceneState::GAMEPLAY || session_->GetCurrentState() == Core::SceneState::TEXT) {
            evilIconImage_.Render();
            if (session_->GetCurrentState() == Core::SceneState::GAMEPLAY) {
                Novice::DrawSpriteRect(300, 80, (int)line_.posi.x, (int)line_.posi.y, (int)line_.size.x, (int)line_.size.y, line_.resource.textureHandle, 0.33f, 1.f, 0, WHITE);
            }
        } else if (session_->GetCurrentState() == Core::SceneState::GAMEOVER_WIN) {

        } else if (session_->GetCurrentState() == Core::SceneState::GAMEOVER_LOSE) {

        }

        Novice::DrawSpriteRect(345, 50,  (int)powerMeter_.posi.x, (int)powerMeter_.posi.y, (int)powerMeter_.size.x, (int)powerMeter_.size.y, powerMeter_.resource.textureHandle, 0.25f, 1.f,0, WHITE);
    }
    void IGUIAction::Shutdown() {
        prevMouseDown_ = false;
    }
}


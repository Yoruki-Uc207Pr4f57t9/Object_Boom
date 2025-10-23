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

    }
    void IGUIAction::Render() {
        bgImage_.Render();
        evilIconImage_.Render();

        Novice::DrawSpriteRect(345, 50,  (int)powerMeter_.posi.x, (int)powerMeter_.posi.y, (int)powerMeter_.size.x, (int)powerMeter_.size.y, powerMeter_.resource.textureHandle, 0.25f, 1.f,0, WHITE);

    }
    void IGUIAction::Shutdown() {
        prevMouseDown_ = false;
    }
}


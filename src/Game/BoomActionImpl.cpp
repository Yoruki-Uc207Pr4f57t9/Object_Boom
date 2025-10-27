#include "Game/IBoomAction.hpp"
#include <vector>
#include <Novice.h>

namespace Game {

    // 初期化
    void IBoomAction::Init() {
        boom_.boomAnime_ = session_->GetResources()->BoomHandle();
        boom_.animeScale = 0.4f;
        boom_.isActive = true;

        int boomWidth = (int)(session_->GetResources()->BoomHandle().resource.size.x * boom_.animeScale);
        int boomHeight = (int)(session_->GetResources()->BoomHandle().resource.size.y * boom_.animeScale);
        boom_.position = { (float)(Core::kWindowWidth / 2 - boomWidth / 2), (float)(Core::kWindowHeight / 2 - boomHeight) };
        
       
        countdownTimer_.Init(
            { 0.f, 0.f }, 5 * 60 * 60, 0,
            Core::COUNT_TIME,
            true,
            boom_.animeScale,
            {
                session_->GetResources()->NumberHandle(0),
                session_->GetResources()->NumberHandle(1),
                session_->GetResources()->NumberHandle(2),
                session_->GetResources()->NumberHandle(3),
                session_->GetResources()->NumberHandle(4),
                session_->GetResources()->NumberHandle(5),
                session_->GetResources()->NumberHandle(6),
                session_->GetResources()->NumberHandle(7),
                session_->GetResources()->NumberHandle(8),
                session_->GetResources()->NumberHandle(9)
            },
            session_->GetResources()->SeparatorHandle()
        );
        countdownTimer_.Pause(false);     
        countdownTimer_.CountDown(true);
       
        countdownTimer_.SetPosition({ (boom_.position.x + boom_.animeScale * 367), (boom_.position.y + boom_.animeScale * 166)});

    }

    void IBoomAction::Input(KeyBoard& kb, Mouse& mouse) {
        kb;
        mouse;
    }

    // 更新
    void IBoomAction::Update() {
        countdownTimer_.UpdateByFrames(1, 60.0f);
    }

    // 描画
    void IBoomAction::Render() {
        
        Novice::DrawSpriteRect((int)boom_.position.x, (int)boom_.position.y, 0, 0, (int)boom_.boomAnime_.resource.size.x, (int)boom_.boomAnime_.resource.size.y,
            boom_.boomAnime_.resource.textureHandle, boom_.animeScale, boom_.animeScale, 0, WHITE);

        countdownTimer_.Render();
        if (session_->GetCurrentState() == Core::SceneState::GAMEPLAY) {
            std::vector<int> rdPW = session_->GetPlayerData()->keychains.at((int)session_->GetPlayerData()->passwordIndex.y);
            for (int i = 0; i < rdPW.size(); i++) {
                auto num = session_->GetResources()->NumberPWHandle(rdPW.at(i));
                Novice::DrawSpriteRect((int)(boom_.position.x + (num.size.x * i) + 100), (int)(boom_.position.y + 150),
                    (int)num.posi.x, (int)num.posi.y, (int)num.size.x, (int)num.size.y,
                    num.resource.textureHandle,
                    0.1f, 1.f, 0, WHITE);
            }
        }
    }

    // 終了
    void IBoomAction::Shutdown() {
        effectCooldown_ = 0;
        boom_ = Entity::Boom();
    }
}

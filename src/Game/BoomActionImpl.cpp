#include "Game/IBoomAction.hpp"

namespace Game {

    // 初期化
    void IBoomAction::Init() {
        countdownTimer_.Init(
            { 0.f, 0.f }, 5 * 60 * 60, 60 * 60,
            Core::COUNT_TIME,
            true,
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

    }

    // 更新
    void IBoomAction::Update() {
        countdownTimer_.UpdateByFrames(1, 60.0f);

    }

    // 描画
    void IBoomAction::Render() {
        countdownTimer_.Render();

    }

    // 終了
    void IBoomAction::Shutdown() {
        effectCooldown_ = 0;
        boom_ = Boom();
    }
}

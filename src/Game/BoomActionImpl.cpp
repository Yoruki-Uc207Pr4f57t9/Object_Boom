#include "Game/IBoomAction.hpp"

namespace Game {

    // 初期化
    void IBoomAction::Init() {

    }

    // 更新
    void IBoomAction::Update() {

    }

    // 描画
    void IBoomAction::Render() {

    }

    // 終了
    void IBoomAction::Shutdown() {
        effectCooldown_ = 0;
        boom_ = Boom();
    }
}

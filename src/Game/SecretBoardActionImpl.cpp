#include "Game/ISecretBoardAction.hpp"
#include <Novice.h>

namespace Game {

    // 初期化
    void ISecretBoardAction::Init() {

    }

    // 入力
    void ISecretBoardAction::Input(KeyBoard& kb, Mouse& mouse) {
        kb;
        mouse;
    }

    // 更新
    void ISecretBoardAction::Update() {

    }

    // 描画
    void ISecretBoardAction::Render() {
        int size = 256;
        Novice::DrawBox((int)(Core::kWindowWidth / 2 - size / 2), (int)(Core::kWindowHeight / 2 + size / 4 ), size, size, 0 , RED, kFillModeWireFrame);
        Novice::DrawEllipse(Core::kWindowWidth / 2, (int)(Core::kWindowHeight / 2 + (size - size / 4)), size / 2, size / 2, 0, RED, kFillModeWireFrame);
    }

    // 終了
    void ISecretBoardAction::Shutdown() {
        pushCooldown_ = 0;
        secretBoard_ = SecretBoard();
    }
}

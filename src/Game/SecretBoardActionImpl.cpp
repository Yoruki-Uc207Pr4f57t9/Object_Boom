#include "Game/ISecretBoardAction.hpp"

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

    }

    // 終了
    void ISecretBoardAction::Shutdown() {
        pushCooldown_ = 0;
        secretBoard_ = SecretBoard();
    }
}

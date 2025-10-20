#include "Game/ISecretBoardAction.hpp"
#include <Novice.h>

namespace Game {

    // 初期化
    void ISecretBoardAction::Init() {
        secretBoard_.passwdAnime_ = session_->GetResources()->SBPasswdHandle();
        secretBoard_.flagAnime_ = session_->GetResources()->SBFlagHandle();
        secretBoard_.isActive = true;



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
        float scaleFL = secretBoard_.flagAnime_.resource.scale * secretBoard_.animeScale;
        int sizeFLX = (int)(secretBoard_.flagAnime_.resource.size.x * scaleFL);
        int sizeFLY = (int)(secretBoard_.flagAnime_.resource.size.y * scaleFL);
        int offsetY = 32;
        int offsetX = 2;
        Novice::DrawBox((int)(Core::kWindowWidth / 2 - sizeFLX / 2) - offsetX, (int)(Core::kWindowHeight / 2 + sizeFLY / 4) - offsetY, sizeFLX, sizeFLY, 0, WHITE, kFillModeSolid);

        float scalePW = secretBoard_.passwdAnime_.resource.scale * secretBoard_.animeScale;
        int sizePWX = (int)(secretBoard_.passwdAnime_.resource.size.x * scalePW);
        int sizePWY = (int)(secretBoard_.passwdAnime_.resource.size.y * scalePW);
        /*Novice::DrawSpriteRect((int)(Core::kWindowWidth / 2 - sizePWX / 2), (int)(Core::kWindowHeight / 2 + sizePWY / 4), 0, 0, (int)secretBoard_.passwdAnime_.resource.size.x, (int)secretBoard_.passwdAnime_.resource.size.y,
            secretBoard_.passwdAnime_.resource.textureHandle, scalePW, scalePW, 0, WHITE);*/



      
        Novice::DrawSpriteRect((int)(Core::kWindowWidth / 2 - sizeFLX / 2) - offsetX, (int)(Core::kWindowHeight / 2 + sizeFLY / 4) - offsetY, 0, 0, (int)secretBoard_.flagAnime_.resource.size.x, (int)secretBoard_.flagAnime_.resource.size.y,
            secretBoard_.flagAnime_.resource.textureHandle, scaleFL, scaleFL, 0, WHITE);
    }

    // 終了
    void ISecretBoardAction::Shutdown() {
        pushCooldown_ = 0;
        secretBoard_ = SecretBoard();
    }
}


#include "Game/ISecretBoardAction.hpp"
#include <Novice.h>

namespace Game {


    // 初期化
    void ISecretBoardAction::Init() {
        secretBoard_.passwdAnime_ = session_->GetResources()->SBPasswdHandle();
        secretBoard_.flagAnime_ = session_->GetResources()->SBFlagHandle();
        secretBoard_.isActive = true;

        float scalePW = secretBoard_.passwdAnime_.resource.scale * secretBoard_.animeScale;
        float sizePWX = (secretBoard_.passwdAnime_.resource.size.x * scalePW);
        float sizePWY = (secretBoard_.passwdAnime_.resource.size.y * scalePW);
        secretBoard_.virtualP.leftTop = { -sizePWX / 2, -sizePWY / 2 };
        secretBoard_.virtualP.rightTop = { sizePWX / 2, -sizePWY / 2 };
        secretBoard_.virtualP.leftBottom = { -sizePWX / 2, sizePWY / 2 };
        secretBoard_.virtualP.rightBottom = { sizePWX / 2, sizePWY / 2 };

        /*secretBoard_.timeValue = static_cast<float>(1 / 10.0f * Core::PI);

        secretBoard_.rotateMatrix = secretBoard_.rotateMatrix.MakeRotateMatrix(secretBoard_.timeValue);*/

        secretBoard_.position = { (Core::kWindowWidth / 2 ), (Core::kWindowHeight / 2 + (sizePWY - (sizePWY / 4))) };

    }

    // 入力
    void ISecretBoardAction::Input(KeyBoard& kb, Mouse& mouse) {
        mouse;

        // test
        if (kb.preKeys[DIK_SPACE] == 0 && kb.keys[DIK_SPACE] != 0) {
            secretBoard_.timeValue++;
        }
        if (kb.ktt.spaceBtn != 0) {
            
            
            

        }
    }

    double deg2rad(double deg) {
        return deg * (Core::PI / 180.0);
    }

    // 更新
    void ISecretBoardAction::Update() {
        /*if (secretBoard_.timeValue >= 10.0f) {
            secretBoard_.timeValue = 0.0f;
        } else {
            secretBoard_.timeValue += 1.f / 60.f; 
        }*/
        
        
        Core::Matrix2x2 rotateMatrix = secretBoard_.rotateMatrix.MakeRotateMatrix((float)(deg2rad(-35 * secretBoard_.timeValue)));

        /*secretBoard_.virtualP.leftTop = rotateMatrix * secretBoard_.virtualP.leftTop;
        secretBoard_.virtualP.rightTop = rotateMatrix * secretBoard_.virtualP.rightTop;
        secretBoard_.virtualP.leftBottom = rotateMatrix * secretBoard_.virtualP.leftBottom;
        secretBoard_.virtualP.rightBottom = rotateMatrix * secretBoard_.virtualP.rightBottom;

        secretBoard_.localP = (secretBoard_.virtualP) + secretBoard_.position;*/

        Core::Vector2 leftTop = rotateMatrix * secretBoard_.virtualP.leftTop;
        Core::Vector2 rightTop = rotateMatrix * secretBoard_.virtualP.rightTop;
        Core::Vector2 leftBottom = rotateMatrix * secretBoard_.virtualP.leftBottom;
        Core::Vector2 rightBottom = rotateMatrix * secretBoard_.virtualP.rightBottom;

        secretBoard_.localP.leftTop = (leftTop) + secretBoard_.position;
        secretBoard_.localP.rightTop = (rightTop) + secretBoard_.position;
        secretBoard_.localP.leftBottom = (leftBottom)+secretBoard_.position;
        secretBoard_.localP.rightBottom = (rightBottom)+secretBoard_.position;

        

    }

    // 描画
    void ISecretBoardAction::Render() {
        float scaleFL = secretBoard_.flagAnime_.resource.scale * secretBoard_.animeScale;
        int sizeFLX = (int)(secretBoard_.flagAnime_.resource.size.x * scaleFL);
        int sizeFLY = (int)(secretBoard_.flagAnime_.resource.size.y * scaleFL);
        int offsetY = 32;
        int offsetX = 2;
        Novice::DrawBox((int)(Core::kWindowWidth / 2 - sizeFLX / 2) - offsetX, (int)(Core::kWindowHeight / 2 + sizeFLY / 4) - offsetY, sizeFLX, sizeFLY, 0, WHITE, kFillModeSolid);

        //float scalePW = secretBoard_.passwdAnime_.resource.scale * secretBoard_.animeScale;
        /*int sizePWX = (int)(secretBoard_.passwdAnime_.resource.size.x * scalePW);
        int sizePWY = (int)(secretBoard_.passwdAnime_.resource.size.y * scalePW);*/
        /*Novice::DrawSpriteRect(
            (int)(Core::kWindowWidth / 2 - sizePWX / 2), 
            (int)(Core::kWindowHeight / 2 + sizePWY / 4), 
            0, 0, 
            (int)secretBoard_.passwdAnime_.resource.size.x, 
            (int)secretBoard_.passwdAnime_.resource.size.y,
            secretBoard_.passwdAnime_.resource.textureHandle, scalePW, scalePW, 0, WHITE);*/
        
        Novice::DrawQuad(
            (int)(secretBoard_.localP.leftTop.x ),
            (int)(secretBoard_.localP.leftTop.y ),
            (int)(secretBoard_.localP.rightTop.x ),
            (int)(secretBoard_.localP.rightTop.y ),
            (int)(secretBoard_.localP.leftBottom.x ),
            (int)(secretBoard_.localP.leftBottom.y ),
            (int)(secretBoard_.localP.rightBottom.x ),
            (int)(secretBoard_.localP.rightBottom.y ),
            0, 0, (int)secretBoard_.passwdAnime_.resource.size.x,
            (int)secretBoard_.passwdAnime_.resource.size.y,

            secretBoard_.passwdAnime_.resource.textureHandle,
            WHITE
        );



      
        Novice::DrawSpriteRect((int)(Core::kWindowWidth / 2 - sizeFLX / 2) - offsetX, (int)(Core::kWindowHeight / 2 + sizeFLY / 4) - offsetY, 0, 0, (int)secretBoard_.flagAnime_.resource.size.x, (int)secretBoard_.flagAnime_.resource.size.y,
            secretBoard_.flagAnime_.resource.textureHandle, scaleFL, scaleFL, 0, WHITE);


    }

    // 終了
    void ISecretBoardAction::Shutdown() {
        pushCooldown_ = 0;
        secretBoard_ = SecretBoard();
    }
}


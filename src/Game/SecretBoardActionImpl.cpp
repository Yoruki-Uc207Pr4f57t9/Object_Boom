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

        secretBoard_.timeValue = 0;
        secretBoard_.position = { (Core::kWindowWidth / 2 ), (Core::kWindowHeight / 2 + (sizePWY - (sizePWY / 4))) };
        RotateFunc_();
    }

    // 入力
    void ISecretBoardAction::Input(KeyBoard& kb, Mouse& mouse) {
        mouse;
        /*if (kb.ktt.spaceBtn != 0 && session_->DetectInputLock()) {
            session_->GetPlayerData()->batteryCount--;
            session_->ResetInputLock();
        } */
        if (!session_->DetectInputLock() && kb.keys[DIK_SPACE] == 0 && kb.preKeys[DIK_SPACE] != 0) {
            session_->ResetInputLock();
            //session_->GetPlayerData()->batteryCount--;
            int y = (int)session_->GetPlayerData()->passwordIndex.y;
            int x = (int)session_->GetPlayerData()->passwordIndex.x;
            int realPW = session_->GetPlayerData()->keychains.at(y).at(x);
            if (realPW == secretBoard_.timeValue) {
                session_->GetPlayerData()->passwordIndex.x++;
                if (session_->GetPlayerData()->passwordIndex.x >= Core::PW_CELL) {
                    session_->GetPlayerData()->passwordIndex.x = 0;
                    session_->GetPlayerData()->passwordIndex.y++;
                    session_->GetPlayerData()->missionCount--;
                }
            } else {
                session_->GetPlayerData()->batteryCount--;
            }

        }
        // Test
        if (kb.keys[DIK_P] == 0 && kb.preKeys[DIK_P] != 0) {
            session_->GetPlayerData()->missionCount--;
        }
    }

   

    // 更新
    void ISecretBoardAction::Update() {
        if (session_->GetGameSetting()->GetCurrentFrame() % 60 == 0) {
            secretBoard_.timeValue++;
        }

        if (secretBoard_.timeValue > 9) {
            secretBoard_.timeValue = 0;
        } else if (secretBoard_.timeValue < 0) {
            secretBoard_.timeValue = 9;
        }
        RotateFunc_();

    }

    void ISecretBoardAction::RotateFunc_() {
        Core::Matrix2x2 rotateMatrix = secretBoard_.rotateMatrix.MakeRotateMatrix((float)(Deg2rad_(-radMap_[secretBoard_.timeValue])));

        Core::Vector2 leftTop = rotateMatrix * secretBoard_.virtualP.leftTop;
        Core::Vector2 rightTop = rotateMatrix * secretBoard_.virtualP.rightTop;
        Core::Vector2 leftBottom = rotateMatrix * secretBoard_.virtualP.leftBottom;
        Core::Vector2 rightBottom = rotateMatrix * secretBoard_.virtualP.rightBottom;

        secretBoard_.localP.leftTop = (leftTop)+secretBoard_.position;
        secretBoard_.localP.rightTop = (rightTop)+secretBoard_.position;
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
        //Novice::DrawBox(0, (int)(Core::kWindowHeight / 2 + sizeFLY / 4) - offsetY, Core::kWindowWidth, sizeFLY, 0, WHITE, kFillModeSolid);

        Novice::DrawBox(0, 0, Core::kWindowWidth, Core::kWindowHeight, 0, WHITE, kFillModeSolid);

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
        secretBoard_ = Entity::SecretBoard();
    }
}


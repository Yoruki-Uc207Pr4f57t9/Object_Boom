#include "Game/Input.hpp"
#include "Game/GameSession.hpp"
#include "Core/Config.hpp"
#include <Novice.h>

namespace Game {

    void RefreshInputDirTimestamp(KeyBoard& keyBoard, GameSetting setting) {
        // [ラムダ式]汎用関数としてキー入力のタイムスタンプ更新をまとめる   
        auto updateTimestamp = [&keyBoard, &setting](int key, int& inputKey) {
            if (keyBoard.keys[key] && inputKey == 0) {
                inputKey = setting.currentFrame;
            } else if (!keyBoard.keys[key]) {
                inputKey = 0;
            }
            };

        // それぞれの方向キーに対して、汎用関数を呼び出す
        updateTimestamp(DIK_W, keyBoard.ktt.up);
        updateTimestamp(DIK_S, keyBoard.ktt.down);
        updateTimestamp(DIK_A, keyBoard.ktt.left);
        updateTimestamp(DIK_D, keyBoard.ktt.right);
        updateTimestamp(DIK_J, keyBoard.ktt.aBtn);
        updateTimestamp(DIK_K, keyBoard.ktt.bBtn);
        updateTimestamp(DIK_RETURN, keyBoard.ktt.enterBtn);
        updateTimestamp(DIK_SPACE, keyBoard.ktt.spaceBtn);
        updateTimestamp(DIK_ESCAPE, keyBoard.ktt.escBtn);
    }

    void KeyBoard::PollKeyboard(KeyBoard& kb, GameSetting setting) {
        std::memcpy(kb.preKeys, kb.keys, 256);
        Novice::GetHitKeyStateAll(kb.keys);
        RefreshInputDirTimestamp(kb, setting);
    }

    void Mouse::Init(Core::ResourceManager* rm) {
        rm;
        //cursorHandle_ = rm->mainSceneBGHandle; // ここは適切なカーソル画像に変更する必要があります
        //clickHandle_ = rm->bgmWaterDropHandle; // ここは適切なクリック音に変更する必要があります
        Novice::SetMouseCursorVisibility(Core::MouseCursor::HIDE_MOUSE);
        isVisible_ = true;
        isEnabled_ = true;
    }

    void Mouse::Update() {
        if (!isVisible_ || !isEnabled_) return;
        int x = 0, y = 0;
        Novice::GetMousePosition(&x, &y);
        position_.x = static_cast<float>(x);
        position_.y = static_cast<float>(y);
    }

    void Mouse::Render() const {
        if (!isVisible_ || !isEnabled_) return;
        
        /*Novice::DrawSpriteRect(
            static_cast<int>(position_.x), static_cast<int>(position_.y),
            0, 0,
            static_cast<int>(cursorHandle_.resource.size.x), static_cast<int>(cursorHandle_.resource.size.y),
            cursorHandle_.resource.textureHandle,
            1.0f, 1.0f, 0.0f, WHITE);*/
        /*Novice::DrawBox(
            static_cast<int>(position_.x), static_cast<int>(position_.y ),
            40, 40, 0.0f, WHITE, kFillModeWireFrame);*/
        Novice::DrawBox(
            static_cast<int>(position_.x - 32 / 2), static_cast<int>(position_.y - 32 / 2),
            32, 32, 0.0f, WHITE, kFillModeWireFrame);
    }

    bool Mouse::IsLeftButtonPressed() const {
        return Novice::IsPressMouse(Core::MouseButton::LEFT_BUTTON);
    }
    bool Mouse::IsRightButtonPressed() const {
        return Novice::IsPressMouse(Core::MouseButton::RIGHT_BUTTON);
    }
    void Mouse::PlayClickSound() {
        if (clickHandle_.handle != -1) {
            //Novice::PlayAudio(clickHandle_.handle, 0, clickHandle_.volume);
        }
    }

} // namespace Game

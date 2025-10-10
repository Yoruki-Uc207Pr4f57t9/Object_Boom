#pragma once
#include "Core/ResourceManager.hpp"
#include "Game/GameSession.hpp"
#include "Core/Math.hpp"

namespace Game {
    struct KeyTimestamp {
        int up = 0, down = 0, left = 0, right = 0, aBtn = 0, bBtn = 0, xBtn = 0, yBtn = 0, enterBtn = 0, escBtn = 0, spaceBtn = 0;
    };

    class KeyBoard {
    public:
        void PollKeyboard(KeyBoard& kb, GameSetting setting);

    public:
        char keys[256]{ 0 };
        char preKeys[256]{ 0 };
        KeyTimestamp ktt{};
        
    };

    class Mouse {
    public:
        void Init(Core::ResourceManager* rm);
        void Update();
        void Render() const;
        const Core::Vector2& GetPosition() const { return position_; }
        bool IsLeftButtonPressed() const;
        bool IsRightButtonPressed() const;
        void PlayClickSound();
        bool isSelected_{ false };
        bool IsVisible() const {
            return isVisible_;
        }

        void Open() {
            isEnabled_ = true;
            isVisible_ = true;
        }
        void Close() {
            isEnabled_ = false;
            isVisible_ = false;
        }
        void SetVisible(bool flag) {
            isVisible_ = flag;
        }
        bool IsEnabled() const {
            return isEnabled_;
        }
    
    private:
        bool isVisible_{ true };
        bool isEnabled_{ true };
        Core::Vector2 position_{ 0.0f, 0.0f };
        Core::AnimeHandle cursorHandle_;
        Core::AudioResource clickHandle_;
        bool leftPressed_;   
        bool leftTriggered_;  
        bool rightPressed_;
        bool rightTriggered_;
    };

}

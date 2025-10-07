#pragma once
#include "Core/ResourceManager.hpp"
#include "Input.hpp"


namespace Game {
    class GameSetting {
    public:
        int  currentFrame{ 0 };
        int  inputLockFrame{ Core::INPUT_LOCK_FRAME };
        bool isGameOver{ false };
        bool isGameClear{ false };
        bool isDebugMode{ false };

        void IncrementFrame() {
            if (currentFrame < INT_MAX) ++currentFrame;
            else currentFrame = 0;
        }
        void ResetInputLock(int frames) { inputLockFrame = frames; }
        bool DetectInputLock() {
            if (inputLockFrame <= 0) {
                return false;
            }
            --inputLockFrame;
            return true;
        }
    };

    class GameSession {
    public: 
        GameSession()
            : resources()
            , setting()
            , mouse()
            , keyboard()
        {}

        Core::ResourceManager       resources;
        GameSetting                 setting;
        Mouse                       mouse;
        KeyBoard                    keyboard;

        

        void ResetInputLock() { setting.ResetInputLock(Core::INPUT_LOCK_FRAME); }
        bool DetectInputLock() { return setting.DetectInputLock(); }

    };

} // namespace Game

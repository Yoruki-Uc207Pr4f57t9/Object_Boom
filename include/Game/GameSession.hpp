#pragma once
#include "Core/ResourceManager.hpp"
#include "Input.hpp"


namespace Game {
    class GameSetting {
    public:
        bool IsGameOver() const { return isGameOver_; }
        void SetGameOver(bool flag) { isGameOver_ = flag; }
        bool IsGameClear() const { return isGameClear_; }
        void SetGameClear(bool flag) { isGameClear_ = flag; }
        bool IsDebugMode() const { return isDebugMode_; }
        void SetDebugMode(bool flag) { isDebugMode_ = flag; }
        

        void IncrementFrame() {
            if (currentFrame_ < INT_MAX) ++currentFrame_;
            else currentFrame_ = 0;
        }
        void ResetInputLock(int frames) { inputLockFrame_ = frames; }
        bool DetectInputLock() {
            if (inputLockFrame_ <= 0) {
                return false;
            }
            --inputLockFrame_;
            return true;
        }
    private:
        int  currentFrame_{ 0 };
        int  inputLockFrame_{ Core::INPUT_LOCK_FRAME };
        bool isGameOver_{ false };
        bool isGameClear_{ false };
        bool isDebugMode_{ false };
    };

    class GameSession {
    public: 
        explicit GameSession(Core::ResourceManager resources, GameSetting setting, Mouse mouse, KeyBoard keyboard)
            : resources_(resources)
            , setting_(setting)
            , mouse_(mouse)
            , keyboard_(keyboard)
        {}

        void ResetInputLock() { setting_.ResetInputLock(Core::INPUT_LOCK_FRAME); }
        bool DetectInputLock() { return setting_.DetectInputLock(); }

    private:
        Core::ResourceManager       resources_;
        GameSetting                 setting_;
        Mouse                       mouse_;
        KeyBoard                    keyboard_;
    };

} // namespace Game

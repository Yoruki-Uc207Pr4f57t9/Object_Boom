#pragma once
#include "Core/ResourceManager.hpp"
#include "Input.hpp"


namespace Game {

    class GameSession {
    public: 
        explicit GameSession(Core::ResourceManager resources, GameSetting setting, Mouse mouse, KeyBoard keyboard)
            : resources_(resources)
            , setting_(setting)
            , mouse_(mouse)
            , keyboard_(keyboard)
        {}
        void SetMouse(Mouse mo) { mouse_ = mo; }
        Mouse* GetMouse() { return &mouse_; }

        void SetKeyBoard(KeyBoard kb) { keyboard_ = kb; }
        KeyBoard* GetKeyBoard() { return &keyboard_; }

        Core::ResourceManager* GetResources() { return &resources_; }

        GameSetting* GetGameSetting() { return &setting_; }
        void SetGameSetting(GameSetting setting) { setting_ = setting; }


        void ResetInputLock() { setting_.ResetInputLock(Core::INPUT_LOCK_FRAME); }
        bool DetectInputLock() { return setting_.DetectInputLock(); }

    private:
        Core::ResourceManager       resources_;
        GameSetting                 setting_;
        Mouse                       mouse_;
        KeyBoard                    keyboard_;
    };

} // namespace Game

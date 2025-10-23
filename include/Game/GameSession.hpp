#pragma once
#include "Core/ResourceManager.hpp"
#include "Input.hpp"
#include "Entity/Entity.hpp"


namespace Game {

    class GameSession {
    public: 
        explicit GameSession()
            : resources_()
            , setting_()
            , mouse_()
            , keyboard_()
            , currentState_(Core::SceneState::MAIN) {
            playerData_.batteryCount = Core::PLAYER_M_LIVES;
            playerData_.missionCount = Core::PLAYER_M_MISSION;
        }
        explicit GameSession(Core::ResourceManager resources, GameSetting setting, Mouse mouse, KeyBoard keyboard)
            : resources_(resources)
            , setting_(setting)
            , mouse_(mouse)
            , keyboard_(keyboard)
            , currentState_(Core::SceneState::MAIN) {
            playerData_.batteryCount = Core::PLAYER_M_LIVES;
            playerData_.missionCount = Core::PLAYER_M_MISSION;
        }
        Core::SceneState GetCurrentState() const { return currentState_; }
        void SetCurrentState(Core::SceneState state) { currentState_ = state; }

        void SetMouse(Mouse mo) { mouse_ = mo; }
        Mouse* GetMouse() { return &mouse_; }

        void SetKeyBoard(KeyBoard kb) { keyboard_ = kb; }
        KeyBoard* GetKeyBoard() { return &keyboard_; }

        Core::ResourceManager* GetResources() { return &resources_; }

        GameSetting* GetGameSetting() { return &setting_; }
        void SetGameSetting(GameSetting setting) { setting_ = setting; }


        void ResetInputLock() { setting_.ResetInputLock(Core::INPUT_LOCK_FRAME); }
        bool DetectInputLock() { return setting_.DetectInputLock(); }  

        Entity::PlayerData* GetPlayerData() { return &playerData_; }

    private:
        Core::ResourceManager       resources_;
        GameSetting                 setting_;
        Mouse                       mouse_;
        KeyBoard                    keyboard_;

        Entity::PlayerData          playerData_;

        Core::SceneState            currentState_;
    };

} // namespace Game

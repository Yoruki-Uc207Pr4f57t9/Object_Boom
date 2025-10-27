#pragma once
#include "Game/IAction.hpp"
#include <vector>


namespace Game {
    
    class ISecretBoardAction : public IAction {
    public:
        explicit ISecretBoardAction(Game::GameSession* session) : session_(session) {}
        void Init();
        void Input(KeyBoard& kb, Mouse& mouse);
        void Update();
        void Render();
        void Shutdown();
        Entity::SecretBoard& GetSecretBoard() { return secretBoard_; }


    private:
        Game::GameSession* session_{ nullptr };


        int pushCooldown_{ 0 };
        Entity::SecretBoard secretBoard_;

        float radMap_[10] = {0.f, 33.f, 69.f, 106.f, 142.f, 180.f, 220.f, 255.f, 293.f, 329.f };

        void RotateFunc_();
        double Deg2rad_(double deg) {
            return deg * (Core::PI / 180.0);
        }


    };
}

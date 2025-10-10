#pragma once
#include <vector>
#include "Game/GameSession.hpp"
#include "Entity/Entity.hpp"

namespace Game {
    
    class ISecretBoardAction {
    public:
        explicit ISecretBoardAction(Game::GameSession* session) : session_(session) {}
        void Init();
        void Input(KeyBoard& kb, Mouse& mouse);
        void Update();
        void Render();
        void Shutdown();
        SecretBoard& GetSecretBoard() { return secretBoard_; }


    private:
        Game::GameSession* session_{ nullptr };
        int pushCooldown_{ 0 };
        SecretBoard secretBoard_;

    };
}

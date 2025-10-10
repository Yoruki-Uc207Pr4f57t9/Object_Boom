#pragma once
#include <vector>
#include "Game/GameSession.hpp"
#include "Entity/Entity.hpp"

namespace Game {

    class IBoomAction {
    public:
        explicit IBoomAction(Game::GameSession* session) : session_(session) {}
        void Init();
        void Update();
        void Render();
        void Shutdown();
        Boom& GetBoom() { return boom_; }


    private:
        Game::GameSession* session_{ nullptr };
        int effectCooldown_{ 0 };
        Boom boom_;

    };
}


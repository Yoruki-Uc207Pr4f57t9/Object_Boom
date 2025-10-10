#pragma once
#include <vector>
#include "Game/GameSession.hpp"
#include "Entity/Entity.hpp"

namespace Game {

    class BoomManager {
    public:
        explicit BoomManager(Game::GameSession* session) : session_(session) {}
        void Init();
        void Input(Game::KeyBoard& kb);
        void Update();
        void Render();
        void Shutdown();
        Boom& GetBoom() { return boom_; }


    private:
        Game::GameSession* session_{ nullptr };
        int fireCooldown_{ 0 };
        Boom boom_;

    };
}


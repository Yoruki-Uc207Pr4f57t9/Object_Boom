#pragma once
#include "Component/Timers.hpp"
#include "Game/GameSession.hpp"
#include "Entity/Entity.hpp"
#include <vector>

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
        int effectCooldown_{ 0 };   //邪魔するもの時間
        Boom boom_;
        Component::RangeClock countdownTimer_;
    };
}


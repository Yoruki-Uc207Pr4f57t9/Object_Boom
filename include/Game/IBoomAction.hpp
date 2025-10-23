#pragma once
#include "Game/IAction.hpp"
#include "Component/Timers.hpp"
#include <vector>

namespace Game {

    class IBoomAction : public IAction {
    public:
        explicit IBoomAction(Game::GameSession* session) : session_(session) {}
        void Init();
        void Input(KeyBoard& kb, Mouse& mouse);
        void Update();
        void Render();
        void Shutdown();
        Entity::Boom& GetBoom() { return boom_; }


    private:
        Game::GameSession* session_{ nullptr };
        int effectCooldown_{ 0 };   //邪魔するもの時間
        Entity::Boom boom_;
        Component::RangeClock countdownTimer_;
    };
}


#pragma once
#include "Game/IAction.hpp"
#include <vector>

namespace Game {
    class IGOWinAction : public IAction {
    public:
        explicit IGOWinAction(Game::GameSession* session) : session_(session) {}
        void Init();
        void Input(KeyBoard& kb, Mouse& mouse);
        void Update();
        void Render();
        void Shutdown();
    private:
        Game::GameSession* session_{ nullptr };

    };
}


#pragma once
#include "Game/IAction.hpp"
#include <vector>

namespace Game {
    class IGOHideAction : public IAction {
    public:
        explicit IGOHideAction(Game::GameSession* session) : session_(session) {}
        void Init();
        void Input(KeyBoard& kb, Mouse& mouse);
        void Update();
        void Render();
        void Shutdown();
    private:
        Game::GameSession* session_{ nullptr };

    };
}

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

        Component::TextSpan winTL01_;
        Component::TextSpan winTL02_;
        Component::TextSpan winTL03_;
        Component::TextSpan winTL04_;
        Component::TextSpan winTL05_;
        Component::TextSpan winTL06_;
        Component::TextSpan winTL07_;
        Component::TextSpan winTL08_;

        int switchTime_ = 2;
        int textCount_ = 1;

        const int timeLineCount_ = 3;

    };
}


#pragma once
#include "Game/IAction.hpp"
#include <vector>

namespace Game {
    enum WIN_TEXTS {
        W_TEXT01,
        W_TEXT02,
        W_TEXT03,
        W_TEXT04,
        W_TEXT05,
        W_TEXT06,
        W_TEXT07,
        W_TEXT08,
        W_COUNT,
    };
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

        int switchTime_ = 4;
        int textCount_ = WIN_TEXTS::W_TEXT01;

        const int timeLineCount_ = WIN_TEXTS::W_COUNT;

    };
}


#pragma once
#include "Game/IAction.hpp"
#include <vector>

namespace Game {
    enum LOSE_TEXTS{
        L_TEXT01,
        L_TEXT02,
        L_TEXT03,
        L_COUNT,
    };
    class IGOLoseAction : public IAction {
    public:
        explicit IGOLoseAction(Game::GameSession* session) : session_(session) {}
        void Init();
        void Input(KeyBoard& kb, Mouse& mouse);
        void Update();
        void Render();
        void Shutdown();

    private:
        Game::GameSession* session_{ nullptr };

        Component::TextSpan loseTL01_;
        Component::TextSpan loseTL02_;
        Core::AnimeHandle loseTL03_;

        int switchTime_ = 5;
        int textCount_ = LOSE_TEXTS::L_TEXT01;

        const int timeLineCount_ = LOSE_TEXTS::L_COUNT;

        
    };
}


#pragma once
#include "Game/IAction.hpp"
#include <vector>

namespace Game {
    enum PLAY_TEXTS {
        P_TEXT01,
        P_TEXT02,
        P_TEXT03,
        P_TEXT04,
        P_TEXT05,
        P_TEXT06,
        P_TEXT07,
        P_TEXT08,
        P_TEXT09,
        P_TEXT10,
        P_TEXT11,
        P_COUNT,
    };
    class IPlayTextAction : public IAction {
    public:
        explicit IPlayTextAction(Game::GameSession* session) : session_(session) {}
        void Init();
        void Input(KeyBoard& kb, Mouse& mouse);
        void Update();
        void Render();
        void Shutdown();

    private:
        Game::GameSession* session_{ nullptr };

        Component::TextSpan playTL01_;
        Component::TextSpan playTL02_;
        Component::TextSpan playTL03_;
        Component::TextSpan playTL04_;
        Component::TextSpan playTL05_;
        Component::TextSpan playTL06_;
        Component::TextSpan playTL07_;
        Component::TextSpan playTL08_;
        Component::TextSpan playTL09_;
        Component::TextSpan playTL10_;
        Component::TextSpan playTL11_;

        int switchTime_ = 5;
        int textCount_ = PLAY_TEXTS::P_TEXT01;

        const int timeLineCount_ = PLAY_TEXTS::P_COUNT;

    };
}
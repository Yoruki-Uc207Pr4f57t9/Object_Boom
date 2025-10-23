#pragma once
#include "Game/IAction.hpp"
#include <vector>

namespace Game {
    struct GameArea {
        Core::Vector2 position;
        Core::Vector2 size;
    };

    class IGUIAction : public IAction{
    public:
        explicit IGUIAction(Game::GameSession* session) : session_(session) {}
        void Init();
        void Input(KeyBoard& kb, Mouse& mouse);
        void Update();
        void Render();
        void Shutdown();

    private:
        Game::GameSession* session_{ nullptr };
        bool prevMouseDown_{ false };
        GameArea area_;

        // UI Components 
        Component::ImageSpan bgImage_;
        Component::ImageSpan evilIconImage_;
        // PowerMeter
        Core::AnimeHandle powerMeter_;

        // [Main]
        Component::TextSpan titleText_;
        Component::Button startButton_;
        Component::Button exitButton_;

        // [ReGame]
        Component::TextSpan reText_;
        Component::Button yesButton_;
        Component::Button noButton_;

        // [GameOver-WIN]
        Component::TextSpan winText_;

        // [GameOver-LOSE]
        Component::TextSpan loseText_;
     };
}
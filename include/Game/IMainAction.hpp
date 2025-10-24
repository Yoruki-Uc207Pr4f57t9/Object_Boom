#pragma once
#include "Game/IAction.hpp"
#include <vector>

namespace Game {

    class IMainAction : public IAction {
    public:
        explicit IMainAction(Game::GameSession* session) : session_(session) {}
        void Init();
        void Input(KeyBoard& kb, Mouse& mouse);
        void Update();
        void Render();
        void Shutdown();
    private:
        Game::GameSession* session_{ nullptr };
        
        int flagSelect_[2] = { 137, 313 };
        int selectIndex_{ Core::RLModel::LEFT };

        Component::ImageSpan flagImage_;

        Component::ImageSpan bgImage_;
        Component::ImageSpan iconImage_;
        Component::TextSpan nameText_;

    };
}

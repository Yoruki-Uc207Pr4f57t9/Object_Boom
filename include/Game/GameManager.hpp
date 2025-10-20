#pragma once
#include "Core/Math.hpp"
#include "Component/Button.hpp"
#include "Component/Text.hpp"
#include "Component/Image.hpp"
#include "Core/ResourceManager.hpp"
#include "Game/Input.hpp"
#include "Game/IBoomAction.hpp"
#include "Game/ISecretBoardAction.hpp"
#include "Game/GameSession.hpp"

namespace Game {

    struct GameArea {
        Core::Vector2 position;
        Core::Vector2 size;
    };

    class GameManager{
    public:
        explicit GameManager(Game::GameSession* session) : session_(session){
            boomAct_ = new Game::IBoomAction(session_);
            secretBoardAct_ = new Game::ISecretBoardAction(session_);
        }

        ~GameManager() {
            delete boomAct_;
        }
        void Reset() {
            prevMouseDown_ = false;
            session_->SetGameSetting(Game::GameSetting());
            session_->GetMouse()->Close();
            session_->SetKeyBoard(Game::KeyBoard());
            boomAct_->Shutdown();
        }
        void InitResources();
        void InitManager() ;
        void OnInput() ;
        void Update() ;
        void Render() ;
        void Shutdown() ;

    private:
        Game::GameSession* session_{ nullptr };
        Game::IBoomAction* boomAct_{ nullptr };
        Game::ISecretBoardAction* secretBoardAct_{ nullptr };
        bool prevMouseDown_{ false };

        int deathWaitFrame_{ 0 };

        GameArea area_;

        // UI Components 
        Component::ImageSpan bgImage_;
        Component::ImageSpan evilIconImage_;


        

        
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

} // namespace Scenes

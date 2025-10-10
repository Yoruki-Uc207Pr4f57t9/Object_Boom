#pragma once
#include "Component/Button.hpp"
#include "Component/Text.hpp"
#include "Component/Image.hpp"
#include "Core/ResourceManager.hpp"
#include "Game/GameSession.hpp"
#include "Game/BoomManager.hpp"
#include "Game/Input.hpp"


namespace Game {

    class GameManager{
    public:
        explicit GameManager(Game::GameSession* session) : session_(session){
            boomMgr_ = new Game::BoomManager(session_);
        }
        ~GameManager() {
            delete boomMgr_;
        }
        void Reset() {
            prevMouseDown_ = false;
            session_->setting = Game::GameSetting();
            session_->mouse.Close();
            session_->keyboard = Game::KeyBoard();
            boomMgr_->Shutdown();
        }
        void InitResources(Core::ResourceManager* rm);
        void InitManager() ;
        void OnInput(Game::KeyBoard& kb, Game::Mouse& mo, Game::GameSetting& setting) ;
        void Update(Game::GameSetting& setting) ;
        void Render() ;
        void Shutdown() ;

    private:
        Game::GameSession* session_{ nullptr };
        Game::BoomManager* boomMgr_{ nullptr };
        bool prevMouseDown_{ false };

        int deathWaitFrame_{ 0 };
        

        // UI Components 
        Component::ImageSpan bgAnime_[2];
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

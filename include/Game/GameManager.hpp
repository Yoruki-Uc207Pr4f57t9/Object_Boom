#pragma once
#include "Core/Math.hpp"
#include "Component/Button.hpp"
#include "Component/Text.hpp"
#include "Component/Image.hpp"
#include "Core/ResourceManager.hpp"
#include "Game/Input.hpp"
#include "Game/IBoomAction.hpp"
#include "Game/ISecretBoardAction.hpp"
#include "Game/IGUIAction.hpp"
#include "Game/GameSession.hpp"

namespace Game {


    class GameManager {
    public:
        explicit GameManager(Game::GameSession* session) : session_(session){
            guiAct_ = new Game::IGUIAction(session);
            boomAct_ = new Game::IBoomAction(session);
            secretBoardAct_ = new Game::ISecretBoardAction(session);
            
        }

        ~GameManager() {
            delete boomAct_;
            delete secretBoardAct_;
            delete guiAct_;
        }
        void Reset() {
            session_->SetGameSetting(Game::GameSetting());
            session_->GetMouse()->Close();
            session_->SetKeyBoard(Game::KeyBoard());
            boomAct_->Shutdown();
            secretBoardAct_->Shutdown();
            guiAct_->Shutdown();

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
        Game::IGUIAction* guiAct_{ nullptr };
    };

} // namespace Scenes

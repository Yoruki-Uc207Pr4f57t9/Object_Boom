#include "Game/GameManager.hpp"

namespace Game {

    // リソースの初期化
    void GameManager::InitResources(Core::ResourceManager* rm) {
        rm->LoadAll();
    }

    // マネージャーの初期化
    void GameManager::InitManager() {

    }

    // 入力処理
    void GameManager::OnInput(Game::KeyBoard& kb, Game::Mouse& mo, Game::GameSetting& setting) {
        kb;
        mo;
        setting;

    }

    // 更新処理
    void GameManager::Update(Game::GameSetting& setting) {
        setting;

    }

    // 描画処理
    void GameManager::Render() {

    }

    // 終了処理
    void GameManager::Shutdown() {
        boomAct_->Shutdown();
        secretBoardAct_->Shutdown();
    }
}


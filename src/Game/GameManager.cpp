#include "Game/GameManager.hpp"

namespace Game {
    void GameManager::InitResources(Core::ResourceManager* rm) {
        rm->LoadAll();
    }

    void GameManager::InitManager() {

    }
    void GameManager::OnInput(Game::KeyBoard& kb, Game::Mouse& mo, Game::GameSetting& setting) {

    }
    void GameManager::Update(Game::GameSetting& setting) {

    }
    void GameManager::Render() {

    }
    void GameManager::Shutdown() {

    }
}


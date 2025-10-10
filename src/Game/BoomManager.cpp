#include "Game/BoomManager.hpp"

namespace Game {


    void BoomManager::Init() {

    }
    void BoomManager::Input(Game::KeyBoard& kb) {

    }
    void BoomManager::Update() {

    }
    void BoomManager::Render() {

    }
    void BoomManager::Shutdown() {
        fireCooldown_ = 0;
        boom_ = Boom();
    }
}

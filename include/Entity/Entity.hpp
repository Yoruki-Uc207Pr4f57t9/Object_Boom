#pragma once
#include "Core/Math.hpp"
#include "Core/ResourceManager.hpp"

namespace Game {
    struct Boom {
        Core::Vector2 position;

        Core::AnimeHandle boomAnime_;
        Core::AnimeHandle boomDeathAnime_;
        bool isActive;
    };

    struct SecretBoard {
        Core::Vector2 position;

        Core::AnimeHandle secretBoardAnime_;
        bool isActive;
    };

    enum class EffectType {
        NONE,
        FREEZE,
        SPARKLE,
        // ここに他のエフェクトタイプを追加可能
    };

}

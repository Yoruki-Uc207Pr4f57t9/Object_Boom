#pragma once
#include "Core/Math.hpp"
#include "Core/ResourceManager.hpp"

namespace Game {
    struct Boom {
        Core::Vector2 position;

        Core::AnimeHandle bossAnime_;
        Core::AnimeHandle bossDeathAnime_;
        bool isActive;
    };

    struct SecretBoard {
        Core::Vector2 position;

        Core::AnimeHandle playerAnime_;
        Core::AnimeHandle playerDeathAnime_;
        bool isActive;
    };

    enum class EffectType {
        NONE,
        FREEZE,
        SPARKLE,
        // ここに他のエフェクトタイプを追加可能
    };

}

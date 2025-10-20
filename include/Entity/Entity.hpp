#pragma once
#include "Core/Math.hpp"
#include "Core/ResourceManager.hpp"

namespace Game {

    struct Boom {
        Core::Vector2 position;

        Core::AnimeHandle boomAnime_;
        Core::AnimeHandle boomDeathAnime_;
        float animeScale = 1;
        bool isActive;
    };

    

    struct SecretBoard {
        Core::Vector2 position;
        Core::AnimeHandle passwdAnime_;
        Core::AnimeHandle flagAnime_;
        Core::AudioHandle timeSound_;
        float animeScale = 1;

        float timeValue = 0;
        Core::Point localP;
        Core::Point virtualP;
        Core::Matrix2x2 rotateMatrix;

        bool isActive;
    };

    enum class EffectType {
        NONE,
        FREEZE,
        SPARKLE,
        // ここに他のエフェクトタイプを追加可能
    };

}

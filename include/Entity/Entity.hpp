#pragma once
#include "Core/Math.hpp"
#include "Core/ResourceManager.hpp"

namespace Game {

    struct Point {
        Core::Vector2 leftTop;
        Core::Vector2 rightTop;
        Core::Vector2 leftBottom;
        Core::Vector2 rightBottom;
    };

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

        int timeValue = 0;
        Point localP;
        Point virtualP;

        bool isActive;
    };

    enum class EffectType {
        NONE,
        FREEZE,
        SPARKLE,
        // ここに他のエフェクトタイプを追加可能
    };

}

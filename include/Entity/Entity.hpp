#pragma once
#include "Core/Math.hpp"
#include "Core/ResourceManager.hpp"

namespace Entity {

    class Boom {
    public:
        Core::Vector2 position;

        Core::AnimeHandle boomAnime_;
        Core::AnimeHandle boomDeathAnime_;
        float animeScale = 1;
        bool isActive;
    };

    

    class SecretBoard {
    public:
        Core::Vector2 position;
        Core::AnimeHandle passwdAnime_;
        Core::AnimeHandle flagAnime_;
        Core::AudioHandle timeSound_;
        float animeScale = 1;

        int timeValue = 0;
        Core::Point localP;
        Core::Point virtualP;
        Core::Matrix2x2 rotateMatrix;

        bool isActive;
    };

    class PlayerData {
    public:
        int batteryCount = 0;
        int missionCount = 0;
    };

    enum class EffectType {
        NONE,
        FREEZE,
        SPARKLE,
        // ここに他のエフェクトタイプを追加可能
    };

}

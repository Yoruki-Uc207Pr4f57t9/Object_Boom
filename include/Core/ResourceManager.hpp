#pragma once
#include <string>
#include "Core/Config.hpp"
#include "Math.hpp"

namespace Core {
    struct AudioResource {
        int handle;
        bool isPlaying;
        bool isLoop;
        float volume;
        AudioResource() : handle(-1), isPlaying(false), isLoop(false), volume(1.0f) {}
    };

    struct AudioHandle {
        AudioResource resource;
        AudioHandle() : resource() {}
        AudioHandle(AudioResource resource) : resource(resource) {}
    };


    struct AnimeResource {
        int textureHandle;
        int frameCount;
        Vector2 size;   // 全体のサイズ
        float scale = 1;
        AnimeResource() : textureHandle(-1), frameCount(0), size({ 0, 0 }), scale(1) {}
        AnimeResource(int textureHandle, int frameCount, Vector2 size, float scale)
            : textureHandle(textureHandle), frameCount(frameCount), size(size), scale(scale) {
        }
    };

    struct AnimeHandle {
        Vector2 posi;  // quadの左上座標
        Vector2 size;   // quadのサイズ
        AnimeResource resource;
        AnimeHandle() : posi({ 0, 0 }), size({ 0, 0 }), resource() {}
        AnimeHandle(Vector2 posi, Vector2 size, AnimeResource resource) : posi(posi), size(size), resource(resource) {}
    };


    class ResourceManager {
    public:
        AnimeHandle BoomHandle();
        AnimeHandle NumberHandle(int num); // 0~9
        AnimeHandle SeparatorHandle(); // :

        AnimeHandle MobileBGHandle();

        AnimeHandle EvilIconHandle();

        AnimeHandle SBPasswdHandle();
        AnimeHandle SBFlagHandle();

        
        void LoadAll();

    private:
        AnimeResource boomRes_;
        AnimeResource numberRes_;
        AnimeResource separatorRes_;
        AnimeResource mobileBGRes_;
        AnimeResource evilIconRes_;

        AnimeResource sBPasswdRes_;
        AnimeResource sBFlagRes_;


    };

} // namespace Core

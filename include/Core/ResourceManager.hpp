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

    struct AnimeResource {
        int textureHandle;
        int frameCount;
        Vector2 size;   // 全体のサイズ
        AnimeResource() : textureHandle(-1), frameCount(0), size({ 0, 0 }) {}
        AnimeResource(int textureHandle, int frameCount, Vector2 size)
            : textureHandle(textureHandle), frameCount(frameCount), size(size) {
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
        
        void LoadAll();

    private:
        AnimeResource boomRes_;
        AnimeResource numberRes_;
        AnimeResource separatorRes_;


    };

} // namespace Core

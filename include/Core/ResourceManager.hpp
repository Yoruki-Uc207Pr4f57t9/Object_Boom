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
        // Anime
        AnimeHandle BoomHandle();
        AnimeHandle NumberHandle(int num); // 0~9
        AnimeHandle SeparatorHandle(); // :

        AnimeHandle MobileBGHandle();
        AnimeHandle MobileMainBGHandle();

        AnimeHandle EvilIconHandle();
        AnimeHandle EvilIconComicHandle();
        

        AnimeHandle SBPasswdHandle();
        AnimeHandle SBFlagHandle();

        AnimeHandle MobilePowerHandle(int num);   // 0~3

        AnimeHandle MainFlagHandle();
        AnimeHandle LoadingHandle();


        // Text
        AnimeHandle EvilIconTextHandle();
        AnimeHandle GoLoseTL01TextHandle();
        AnimeHandle GoLoseTL02TextHandle();
        AnimeHandle GoLoseTL03ImageHandle();

        AnimeHandle GoWinTL01TextHandle();
        AnimeHandle GoWinTL02TextHandle();
        AnimeHandle GoWinTL03TextHandle();
        AnimeHandle GoWinTL04TextHandle();
        AnimeHandle GoWinTL05TextHandle();
        AnimeHandle GoWinTL06TextHandle();
        AnimeHandle GoWinTL07TextHandle();
        AnimeHandle GoWinTL08TextHandle();

        AnimeHandle GoHideTextHandle();

        AnimeHandle TL01PlayerText01Handle();
        AnimeHandle TL02EvilText01Handle();
        AnimeHandle TL03PlayerText02Handle();
        AnimeHandle TL04EvilText02Handle();
        AnimeHandle TL05PlayerText03Handle();
        AnimeHandle TL06EvilText03Handle();
        AnimeHandle TL07PlayerText04Handle();
        AnimeHandle TL08EvilText04Handle();
        AnimeHandle TL09EvilText05Handle();
        AnimeHandle TL10PlayerText05Handle();
        AnimeHandle TL11EvilText06Handle();

        

        
        void LoadAll();

    private:
        AnimeResource boomRes_;
        AnimeResource numberRes_;
        AnimeResource separatorRes_;

        AnimeResource mobileBGRes_;
        AnimeResource mobileMainBGRes_;
        AnimeResource evilIconRes_;
        AnimeResource evilIconComicRes_;
        

        AnimeResource sBPasswdRes_;
        AnimeResource sBFlagRes_;

        AnimeResource mobilePowerRes_;

        AnimeResource mainFlagRes_;

        AnimeResource loadingRes_;

        // Text
        AnimeResource evilIconNameRes_;
        AnimeResource goHideTextRes_;

        AnimeResource evilTL02Text01Res_;
        AnimeResource evilTL04Text02Res_;
        AnimeResource evilTL06Text03Res_;
        AnimeResource evilTL08Text04Res_;
        AnimeResource evilTL09Text05Res_;
        AnimeResource evilTL11Text06Res_;

        AnimeResource playerTL01Text01Res_;
        AnimeResource playerTL03Text02Res_;
        AnimeResource playerTL05Text03Res_;
        AnimeResource playerTL07Text04Res_;
        AnimeResource playerTL10Text05Res_;

        // GameOver Text
        AnimeResource goLoseTL01TextRes_;
        AnimeResource goLoseTL02TextRes_;
        AnimeResource goLoseTL03ImageRes_;

        AnimeResource goWinTL01TextRes_;
        AnimeResource goWinTL02TextRes_;
        AnimeResource goWinTL03TextRes_;
        AnimeResource goWinTL04TextRes_;
        AnimeResource goWinTL05TextRes_;
        AnimeResource goWinTL06TextRes_;
        AnimeResource goWinTL07TextRes_;
        AnimeResource goWinTL08TextRes_;





    };

} // namespace Core

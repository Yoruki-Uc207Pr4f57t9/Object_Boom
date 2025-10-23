#include "Core/ResourceManager.hpp"
#include <Novice.h>
#include <stdexcept>


namespace Core {

    void ResourceManager::LoadAll() {
        boomRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/Boom[815x360].png"), 1, { 815, 360 }, 1);
        numberRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/Number[430x74][43x74_10].png"), 10, { 430, 74 }, 1);
        separatorRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/Separator[17x74].png"), 1, { 17, 74 }, 1);

        mobileBGRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/Mobile[480x720].png"), 1,{480, 720}, 1);
        evilIconRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/Evil[1024x1536].png"), 1 , {1024,1536}, 0.1f);

        sBPasswdRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/SecretBoard_Password_Type_02[1024x1024].png"), 1, { 1024, 1024 }, 0.25f);
        sBFlagRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/SecretBoard_Flag[770x810].png"), 1, { 770, 810 }, 0.36f);

        mobilePowerRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/Power[128x15][32x15_4].png"), 4, { 128, 15 }, 1);

    }

    AnimeHandle ResourceManager::BoomHandle() {
        return AnimeHandle({ 0.0f, 0.0f }, boomRes_.size, boomRes_);
    }

    AnimeHandle ResourceManager::NumberHandle(int num) {
        if (num < 0 || num > 9) {
            throw std::out_of_range("NumberHandle: num must be between 0 and 9");
        }
        return AnimeHandle({ (float)(num * 43), 0.0f }, { 43 , 74 }, numberRes_);
    }

    AnimeHandle ResourceManager::SeparatorHandle() {
        return AnimeHandle({ 0.0f, 0.0f }, separatorRes_.size, separatorRes_);
    }


    AnimeHandle ResourceManager::MobileBGHandle() {
        return AnimeHandle({ 0.0f, 0.0f }, mobileBGRes_.size, mobileBGRes_);
    };
    

    AnimeHandle ResourceManager::EvilIconHandle() {
        return AnimeHandle({ 0.0f, 0.0f }, evilIconRes_.size, evilIconRes_);
    };

    
    AnimeHandle ResourceManager::SBPasswdHandle() {
        return AnimeHandle({ 0.0f, 0.0f }, sBPasswdRes_.size, sBPasswdRes_);
    };

    AnimeHandle ResourceManager::SBFlagHandle() {
        return AnimeHandle({ 0.0f, 0.0f }, sBFlagRes_.size, sBFlagRes_);
    };

    AnimeHandle ResourceManager::MobilePowerHandle(int num) {
        return AnimeHandle({(float)(num * 32), 0.0f}, { 32, 15 }, mobilePowerRes_);
    };

} // namespace Core


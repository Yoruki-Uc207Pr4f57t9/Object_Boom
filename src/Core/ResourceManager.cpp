#include "Core/ResourceManager.hpp"
#include <Novice.h>
#include <stdexcept>


namespace Core {

    void ResourceManager::LoadAll() {
        boomRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/Boom[815x360].png"), 1, { 815, 360 });
        numberRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/Number[430x74][43x74_10].png"), 10, { 430, 74 });
        separatorRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/Separator[17x74].png"), 1, { 17, 74 });

    }

    AnimeHandle ResourceManager::BoomHandle() {
        return AnimeHandle({ 0.0f, 0.0f }, { 815, 360 }, boomRes_);
    }

    AnimeHandle ResourceManager::NumberHandle(int num) {
        if (num < 0 || num > 9) {
            throw std::out_of_range("NumberHandle: num must be between 0 and 9");
        }
        return AnimeHandle({ (float)(num * 43), 0.0f }, { 43, 74 }, numberRes_);
    }

    AnimeHandle ResourceManager::SeparatorHandle() {
        return AnimeHandle({ 0.0f, 0.0f }, { 17, 74 }, separatorRes_);
    }



} // namespace Core


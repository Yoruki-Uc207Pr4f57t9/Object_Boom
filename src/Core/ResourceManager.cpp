#include "Core/ResourceManager.hpp"
#include <Novice.h>
#include <stdexcept>


namespace Core {

    void ResourceManager::LoadAll() {
        boomRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/Boom[815x360].png"), 1, { 815, 360 }, 1);
        numberRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/Number[430x74][43x74_10].png"), 10, { 430, 74 }, 1);
        separatorRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/Separator[17x74].png"), 1, { 17, 74 }, 1);

        mobileBGRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/Mobile[480x720].png"), 1,{480, 720}, 1);
        mobileMainBGRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/Mobile_Main[480x720].png"), 1,{480, 720}, 1);
        evilIconRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/Evil01[780x1024].png"), 1 , {780,1024}, 0.1f);
        evilIconComicRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/Evil_Icon[1024x1024].png"), 1 , {1024,1024}, 0.16f);
        evilIconNameRes_ = AnimeResource(Novice::LoadTexture("./Assets/Text/Icon_Name[220x32].png"), 1, { 220, 32 }, 1.f);

        sBPasswdRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/SecretBoard_Password_Type_02[1024x1024].png"), 1, { 1024, 1024 }, 0.25f);
        sBFlagRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/SecretBoard_Flag[770x810].png"), 1, { 770, 810 }, 0.36f);

        mobilePowerRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/Power[128x15][32x15_4].png"), 4, { 128, 15 }, 1);
        lineRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/Line[240x100][80x100_3].png"), 3, { 240, 100 }, 1);


        mainFlagRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/Flag[70x78].png"), 1, { 70, 78 }, 0.3f);

        loadingRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/Loading[1024x1024].png"), 1, { 1024, 1024 }, 1.f);

        goLoseTL01TextRes_ = AnimeResource(Novice::LoadTexture("./Assets/Text/GO_Lose_TL_01=Text_E_01[298x47].png"), 1, { 298, 47 }, 1.f);
        goLoseTL02TextRes_ = AnimeResource(Novice::LoadTexture("./Assets/Text/GO_Lose_TL_02=Text_O_00[420x90].png"), 1, {420, 90}, 1.f);
        goLoseTL03ImageRes_ = AnimeResource(Novice::LoadTexture("./Assets/Images/GO_Lose_TL_03=Image[1024x1024].png"), 1, { 1024,1024 }, 0.3f);
        goHideTextRes_ = AnimeResource(Novice::LoadTexture("./Assets/Text/GO_Hide_Text_O_00[360x90].png"), 1, { 360,90 }, 1.f);
       
        goWinTL01TextRes_ = AnimeResource(Novice::LoadTexture("./Assets/Text/GO_Win_TL_01=Text_E_01[258x47].png"), 1, { 258,47 }, 1.f);
        goWinTL02TextRes_ = AnimeResource(Novice::LoadTexture("./Assets/Text/GO_Win_TL_02=Text_E_02[251x47].png"), 1, { 251,47 }, 1.f);
        goWinTL03TextRes_ = AnimeResource(Novice::LoadTexture("./Assets/Text/GO_Win_TL_03=Text_E_03[305x47].png"), 1, { 305,47 }, 1.f);
        goWinTL04TextRes_ = AnimeResource(Novice::LoadTexture("./Assets/Text/GO_Win_TL_04=Text_P_01[420x30].png"), 1, { 420,30 }, 1.f);
        goWinTL05TextRes_ = AnimeResource(Novice::LoadTexture("./Assets/Text/GO_Win_TL_05=Text_P_02[420x30].png"), 1, { 420,30 }, 1.f);
        goWinTL06TextRes_ = AnimeResource(Novice::LoadTexture("./Assets/Text/GO_Win_TL_06=Text_P_03[330x30].png"), 1, { 330,30 }, 1.f);
        goWinTL07TextRes_ = AnimeResource(Novice::LoadTexture("./Assets/Text/GO_Win_TL_07=Text_E_04[97x47].png"), 1, { 97,47 }, 1.f);
        goWinTL08TextRes_ = AnimeResource(Novice::LoadTexture("./Assets/Text/GO_Win_TL_08=Text_O_00[280x60].png"), 1, { 280,60 }, 1.f);

        playerTL01Text01Res_ = AnimeResource(Novice::LoadTexture("./Assets/Text/TL_01=Player_Text_01[150x30].png"), 1, { 150,30 }, 1.f);
        evilTL02Text01Res_ = AnimeResource(Novice::LoadTexture("./Assets/Text/TL_02=Evil_Text_01[164x47].png"), 1, { 164,47 }, 1.f);
        playerTL03Text02Res_ = AnimeResource(Novice::LoadTexture("./Assets/Text/TL_03=Player_Text_02[190x30].png"), 1, { 190,30 }, 1.f);
        evilTL04Text02Res_ = AnimeResource(Novice::LoadTexture("./Assets/Text/TL_04=Evil_Text_02[182x70].png"), 1, { 182,70 }, 1.f);
        playerTL05Text03Res_ = AnimeResource(Novice::LoadTexture("./Assets/Text/TL_05=Player_Text_03[190x30].png"), 1, { 190,30 }, 1.f);
        evilTL06Text03Res_ = AnimeResource(Novice::LoadTexture("./Assets/Text/TL_06=Evil_Text_03[203x93].png"), 1, { 203,93 }, 1.f);
        playerTL07Text04Res_ = AnimeResource(Novice::LoadTexture("./Assets/Text/TL_07=Player_Text_04[50x30].png"), 1, { 50,30 }, 1.f);
        evilTL08Text04Res_ = AnimeResource(Novice::LoadTexture("./Assets/Text/TL_08=Evil_Text_04[184x70].png"), 1, { 184,70 }, 1.f);
        evilTL09Text05Res_ = AnimeResource(Novice::LoadTexture("./Assets/Text/TL_09=Evil_Text_05[182x116].png"), 1, { 182,116 }, 1.f);
        playerTL10Text05Res_ = AnimeResource(Novice::LoadTexture("./Assets/Text/TL_10=Player_Text_05[450x30].png"), 1, { 450,30 }, 1.f);
        evilTL11Text06Res_ = AnimeResource(Novice::LoadTexture("./Assets/Text/TL_11=Evil_Text_06[199x93].png"), 1, { 199,93 }, 1.f);
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
    
    AnimeHandle ResourceManager::MobileMainBGHandle() {
        return AnimeHandle({ 0.0f, 0.0f }, mobileMainBGRes_.size, mobileMainBGRes_);
    };


    AnimeHandle ResourceManager::EvilIconComicHandle() {
        return AnimeHandle({ 0.0f, 0.0f }, evilIconComicRes_.size, evilIconComicRes_);
    }

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

    AnimeHandle ResourceManager::LineHandle(int num) {
        return AnimeHandle({ (float)(num * 80), 0.0f }, { 80, 100 }, lineRes_);
    };

    AnimeHandle ResourceManager::MainFlagHandle() {
        return AnimeHandle({ 0.0f, 0.0f }, mainFlagRes_.size, mainFlagRes_);
    };

    // Text
    AnimeHandle ResourceManager::EvilIconTextHandle() {
        return AnimeHandle({ 0.0f, 0.0f }, evilIconNameRes_.size, evilIconNameRes_);
    };

    AnimeHandle ResourceManager::LoadingHandle() {
        return AnimeHandle({0.f, 0.f}, loadingRes_.size, loadingRes_);
    }

    AnimeHandle ResourceManager::GoLoseTL01TextHandle() {
        return AnimeHandle({ 0.f, 0.f }, goLoseTL01TextRes_.size, goLoseTL01TextRes_);
    }
    AnimeHandle ResourceManager::GoLoseTL02TextHandle() {
        return AnimeHandle({ 0.f, 0.f }, goLoseTL02TextRes_.size, goLoseTL02TextRes_);
    }
    AnimeHandle ResourceManager::GoLoseTL03ImageHandle() {
        return AnimeHandle({ 0.f, 0.f }, goLoseTL03ImageRes_.size, goLoseTL03ImageRes_);
    }

    AnimeHandle ResourceManager::GoHideTextHandle() {
        return AnimeHandle({ 0.f, 0.f }, goHideTextRes_.size, goHideTextRes_);
    }

    AnimeHandle ResourceManager::GoWinTL01TextHandle() {
        return AnimeHandle({ 0.f, 0.f }, goWinTL01TextRes_.size, goWinTL01TextRes_);
    }
    AnimeHandle ResourceManager::GoWinTL02TextHandle() {
        return AnimeHandle({ 0.f, 0.f }, goWinTL02TextRes_.size, goWinTL02TextRes_);
    }
    AnimeHandle ResourceManager::GoWinTL03TextHandle() {
        return AnimeHandle({ 0.f, 0.f }, goWinTL03TextRes_.size, goWinTL03TextRes_);
    }
    AnimeHandle ResourceManager::GoWinTL04TextHandle() {
        return AnimeHandle({ 0.f, 0.f }, goWinTL04TextRes_.size, goWinTL04TextRes_);
    }
    AnimeHandle ResourceManager::GoWinTL05TextHandle() {
        return AnimeHandle({ 0.f, 0.f }, goWinTL05TextRes_.size, goWinTL05TextRes_);
    }
    AnimeHandle ResourceManager::GoWinTL06TextHandle() {
        return AnimeHandle({ 0.f, 0.f }, goWinTL06TextRes_.size, goWinTL06TextRes_);
    }
    AnimeHandle ResourceManager::GoWinTL07TextHandle() {
        return AnimeHandle({ 0.f, 0.f }, goWinTL07TextRes_.size, goWinTL07TextRes_);
    }
    AnimeHandle ResourceManager::GoWinTL08TextHandle() {
        return AnimeHandle({ 0.f, 0.f }, goWinTL08TextRes_.size, goWinTL08TextRes_);
    }

    AnimeHandle ResourceManager::TL01PlayerText01Handle() {
        return AnimeHandle({ 0.f, 0.f }, playerTL01Text01Res_.size, playerTL01Text01Res_);
    }
    AnimeHandle ResourceManager::TL02EvilText01Handle() {
        return AnimeHandle({ 0.f, 0.f }, evilTL02Text01Res_.size, evilTL02Text01Res_);
    }
    AnimeHandle ResourceManager::TL03PlayerText02Handle() {
        return AnimeHandle({ 0.f, 0.f }, playerTL03Text02Res_.size, playerTL03Text02Res_);
    }
    AnimeHandle ResourceManager::TL04EvilText02Handle() {
        return AnimeHandle({ 0.f, 0.f }, evilTL04Text02Res_.size, evilTL04Text02Res_);
    }
    AnimeHandle ResourceManager::TL05PlayerText03Handle() {
        return AnimeHandle({ 0.f, 0.f }, playerTL05Text03Res_.size, playerTL05Text03Res_);
    }
    AnimeHandle ResourceManager::TL06EvilText03Handle() {
        return AnimeHandle({ 0.f, 0.f }, evilTL06Text03Res_.size, evilTL06Text03Res_);
    }
    AnimeHandle ResourceManager::TL07PlayerText04Handle() {
        return AnimeHandle({ 0.f, 0.f }, playerTL07Text04Res_.size, playerTL07Text04Res_);
    }
    AnimeHandle ResourceManager::TL08EvilText04Handle() {
        return AnimeHandle({ 0.f, 0.f }, evilTL08Text04Res_.size, evilTL08Text04Res_);
    }
    AnimeHandle ResourceManager::TL09EvilText05Handle() {
        return AnimeHandle({ 0.f, 0.f }, evilTL09Text05Res_.size, evilTL09Text05Res_);
    }
    AnimeHandle ResourceManager::TL10PlayerText05Handle() {
        return AnimeHandle({ 0.f, 0.f }, playerTL10Text05Res_.size, playerTL10Text05Res_);
    }
    AnimeHandle ResourceManager::TL11EvilText06Handle() {
        return AnimeHandle({ 0.f, 0.f }, evilTL11Text06Res_.size, evilTL11Text06Res_);
    }

} // namespace Core


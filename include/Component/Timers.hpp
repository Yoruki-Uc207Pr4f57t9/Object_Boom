#pragma once
#include <Novice.h>
#include <string>
#include <cstdio>
#include <math.h>
#include <stdexcept>
#include <vector>
#include "Core/ResourceManager.hpp"


namespace Component {
    class RangeClock {
    public:
        // startSec/endSec: 顯示的時間範圍（秒）
        // durationSec: 實際跑完所需時間（秒）
        explicit RangeClock(Core::Vector2 posi = {0,0}, float startSec = 0.f, float endSec = 0.f, float durationSec = 1.f, bool paused = true, 
            std::vector<Core::AnimeHandle> handles = {}, Core::AnimeHandle amHandle = {}, Core::AnimeHandle splitHandle = {})
            : position_(posi), startSec_(startSec), endSec_(endSec), durationSec_(max(0.0001f, durationSec)),
            elapsedSec_(0.f), paused_(paused), digitHandle_(handles), amHandle_(amHandle), splitHandle_(splitHandle){
        }

        void Init(Core::Vector2 posi, float startSec, float endSec, float durationSec,
            std::vector<Core::AnimeHandle> handles, Core::AnimeHandle amHandle, Core::AnimeHandle splitHandle) {
            amHandle_ = amHandle;
            splitHandle_ = splitHandle;
            position_ = posi;
            startSec_ = startSec;
            endSec_ = endSec;
            durationSec_ = max(0.0001f, durationSec);
            elapsedSec_ = 0.f;
            digitHandle_ = handles;
        }
        void SetAmHandle(Core::AnimeHandle handle) { amHandle_ = handle; }
        void SetSplitHandle(Core::AnimeHandle handle) { splitHandle_ = handle; }
        void SetDigitHandles(std::vector<Core::AnimeHandle> handles) { digitHandle_ = handles; }
        void SetPosition(Core::Vector2 posi) { position_ = posi; }
        Core::Vector2 GetSize() {
            return {
                (amHandle_.resource.size.x + 10 + 25 * 2 + 10 + 10 + 10 + 25 * 2 + 10 + 10 + 10 + 25 * 2),
                amHandle_.resource.size.y
            };

        }

        void Reset(float startSec, float endSec, float durationSec) {
            startSec_ = startSec;
            endSec_ = endSec;
            durationSec_ = max(0.0001f, durationSec);
            elapsedSec_ = 0.f;
        }   

        void Pause(bool p) { paused_ = p; }

        void Update(float dt) {
            if (paused_) return;
            elapsedSec_ += dt;
            if (elapsedSec_ > durationSec_) elapsedSec_ = durationSec_;
            if (elapsedSec_ < 0.f)          elapsedSec_ = 0.f;
        }

        // 0..1 的進度（clamp）
        float GetRatio() const {
            float t = elapsedSec_ / durationSec_;
            if (t < 0.f) t = 0.f;
            if (t > 1.f) t = 1.f;
            return t;
        }

        // 映射後的「顯示秒數」：從 startSec_ 線性插值到 endSec_
        float GetMappedTimeSec() const {
            float t = GetRatio();
            return startSec_ + (endSec_ - startSec_) * t; // 可正可反
        }

        bool IsFinished() const { return elapsedSec_ >= durationSec_; }

        // 若你用「幀」：提供個便捷更新
        void UpdateByFrames(int frames, float fps) {
            Update(frames / max(0.0001f, fps));
        }

        int GetTime() const {
            return static_cast<int>(GetMappedTimeSec());
        }

        // 以 MM:SS 格式輸出（向下取整）
        void Render() const {
            int total = static_cast<int>(GetMappedTimeSec());
            if (total < 0) {
                total = 0;
            }
            int hours = total / 3600;
            int minutes = (total % 3600) / 60;
            int seconds = total % 60;
            std::string hoursStr = std::to_string(hours);
            std::string minutesStr = std::to_string(minutes);
            std::string secondsStr = std::to_string(seconds);
            if (hours < 10) {
                hoursStr = "0" + hoursStr;
            }
            if (minutes < 10) {
                minutesStr = "0" + minutesStr;
            }
            if (seconds < 10) {
                secondsStr = "0" + secondsStr;
            }

            int offsetX = (int)position_.x;
            Novice::DrawSpriteRect(offsetX, (int)position_.y,
                (int)0, (int)0, (int)amHandle_.resource.size.x, (int)amHandle_.resource.size.y,
                amHandle_.resource.textureHandle,
                1.f, 1.0f, 0.0f, WHITE);
            offsetX += (int)amHandle_.resource.size.x; 
            offsetX += 10;
            for (int i = 0; i < hoursStr.length(); ++i) {
                int idx = std::stoi(std::string(1, hoursStr[i]));
                if (i < digitHandle_.size()) {
                    Novice::DrawSpriteRect(offsetX, (int)position_.y,
                        (int)digitHandle_[idx].posi.x, (int)digitHandle_[idx].posi.y, (int)digitHandle_[idx].size.x, (int)digitHandle_[idx].size.y,
                        digitHandle_[idx].resource.textureHandle,
                        0.1f, 1.0f, 0.0f, WHITE);
                    offsetX += (int)digitHandle_[idx].size.x;
                }
            }
            offsetX += 10;
            Novice::DrawSpriteRect(offsetX, (int)position_.y,
                (int)0, (int)0, (int)splitHandle_.resource.size.x, (int)splitHandle_.resource.size.y,
                splitHandle_.resource.textureHandle,
                1.f, 1.0f, 0.0f, WHITE);
            offsetX += (int)splitHandle_.resource.size.x;
            offsetX += 10;
            for(int i = 0; i < minutesStr.length(); ++i) {
                int idx = std::stoi(std::string(1, minutesStr[i]));
                if (i < digitHandle_.size()) {
                    Novice::DrawSpriteRect(offsetX, (int)position_.y,
                        (int)digitHandle_[idx].posi.x, (int)digitHandle_[idx].posi.y, (int)digitHandle_[idx].size.x, (int)digitHandle_[idx].size.y,
                        digitHandle_[idx].resource.textureHandle,
                        0.1f, 1.0f, 0.0f, WHITE);
                    offsetX += (int)digitHandle_[idx].size.x;
                }
            }
            offsetX += 10;
            Novice::DrawSpriteRect(offsetX, (int)position_.y,
                (int)0, (int)0, (int)splitHandle_.resource.size.x, (int)splitHandle_.resource.size.y,
                splitHandle_.resource.textureHandle,
                1.f, 1.0f, 0.0f, WHITE);
            offsetX += (int)splitHandle_.resource.size.x;
            offsetX += 10;
            for (int i = 0; i < secondsStr.length(); ++i) {
                int idx = std::stoi(std::string(1, secondsStr[i]));
                if (i < digitHandle_.size()) {
                    Novice::DrawSpriteRect(offsetX, (int)position_.y,
                        (int)digitHandle_[idx].posi.x, (int)digitHandle_[idx].posi.y, (int)digitHandle_[idx].size.x, (int)digitHandle_[idx].size.y,
                        digitHandle_[idx].resource.textureHandle,
                        0.1f, 1.0f, 0.0f, WHITE);
                    offsetX += (int)digitHandle_[idx].size.x;
                }
            }

        }


    private:
        float startSec_;     // 顯示起點（秒）
        float endSec_;       // 顯示終點（秒）
        float durationSec_;  // 實際跑完需要的秒數
        float elapsedSec_;   // 已經跑了幾秒（對 duration 計）
        bool  paused_;

        Core::AnimeHandle amHandle_;
        Core::AnimeHandle splitHandle_;
        Core::Vector2 position_;
        std::vector<Core::AnimeHandle> digitHandle_;
    };
}
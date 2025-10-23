#pragma once
#include "Core/Math.hpp"
#include "Game/GameSession.hpp"
#include "Game/GameSetting.hpp"
#include "Game/Input.hpp"
#include "Entity/Entity.hpp"
#include "Component/Button.hpp"
#include "Component/Image.hpp"
#include "Component/Text.hpp"
#include "Component/Timers.hpp"


namespace Core { class Vector2; class Matrix2x2; }
namespace Game { class GameSession; class GameSetting; class KeyBoard; class Mouse;  }
namespace Entity { class Boom; class SecretBoard; }
namespace Component { class Button; class ImageSpan; class TextSpan; class RangeClock; }

namespace Game {

    class IAction {
    public:
        virtual ~IAction() = default;
        virtual void Init() = 0;
        virtual void Input(KeyBoard& kb, Mouse& mouse) = 0;
        virtual void Update() = 0;
        virtual void Render() = 0;
        virtual void Shutdown() = 0;
    };

} // namespace Scenes

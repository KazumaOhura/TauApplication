#ifndef GAME_APP_H_
#define GAME_APP_H_
#include "App.h"
namespace Tau {
class GameBase : public App {
public:
  GameBase(const HINSTANCE& hInstance, const Type::tstring& name)
      : App(hInstance, name) {}
  virtual ~GameBase() {}

  virtual void Initialize() = 0;
  virtual void Run() final;
  virtual void UpdateLogic() = 0;
  virtual void UpdateRender() = 0;
  virtual void Destroy() = 0;

  GameBase(const GameBase&) = delete;
  GameBase& operator=(const GameBase&) = delete;
};
}  // namespace Tau
#endif

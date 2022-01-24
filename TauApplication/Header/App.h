#ifndef APP_H_
#define APP_H_
#include <Windows.h>

#include "../Include/TString.h"
namespace Tau {
class App {
public:
  App(const HINSTANCE& hInstance, const Type::tstring& name) {
    App::m_hInstance = hInstance;
    App::m_name = name;
  }
  virtual ~App() {}

  virtual void Initialize() = 0;
  virtual void Run() = 0;
  virtual void Terminate() = 0;
  virtual void Destroy() = 0;

  static inline HINSTANCE GetInstanceHandle() noexcept { return m_hInstance; }
  static inline Type::tstring GetName() noexcept { return m_name; }

  App(const App&) = delete;
  App& operator=(const App&) = delete;

private:
  static HINSTANCE m_hInstance;
  static Type::tstring m_name;
};
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

  static DWORD GetFrame() { return GameBase::m_frame; }

  GameBase(const GameBase&) = delete;
  GameBase& operator=(const GameBase&) = delete;

private:
  static DWORD m_frame;
};
}  // namespace Tau
#endif

#ifndef MAIN_H_
#define MAIN_H_
#include <memory>

#include "../TauApplication/Header/App.h"
#include "../TauApplication/Header/GameBase.h"
#include "../TauApplication/Header/Window.h"
#include "../TauApplication/Include/TString.h"
namespace Test {
using namespace Tau;
class MyApp : public Tau::App {
public:
  MyApp(HINSTANCE hInstance, Type::tstring appName)
      : Tau::App(hInstance, appName) {}
  // Window生成、デバイス初期化
  void Initialize() final;
  void Run() final;
  void Terminate() final {
    //強制終了
  }
  void Destroy() final {
    //終了処理
  }

private:
  // Graphic, Sound, Window等のデバイス群を持つ
  std::unique_ptr<Tau::Window> m_Window;
  static LRESULT CALLBACK WndProc(HWND hWnd, UINT iMsg, WPARAM wParam,
                                  LPARAM lParam);
};
}  // namespace Test
#endif

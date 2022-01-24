#include "main.h"

#include <tchar.h>

#include <memory>

#include "../TauApplication/Header/App.h"
#include "../TauApplication/Header/Window.h"
#include "../TauApplication/Include/RectSize.h"
#include "../TauApplication/Include/TString.h"

#pragma comment(lib, "../Debug/TauApplication.lib")
#pragma comment(lib, "winmm.lib")

INT WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
                   _In_ LPSTR lpCmdLine, _In_ INT nCmdShow) {
  //メモリリーク検知
  _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

  std::unique_ptr<Tau::App> app =
      std::make_unique<Test::MyApp>(hInstance, _T("Test"));
  app->Initialize();
  app->Run();
  app->Destroy();
}

namespace Test {
using namespace Tau;
void MyApp::Initialize() {
  this->m_Window =
      std::make_unique<Window>(this->GetName(), this->GetInstanceHandle(),
                               Type::RectSize(1280.0f, 720.0f), MyApp::WndProc);
}

void MyApp::Run() {
  //ゲームのメインループ
  DWORD Prev = timeGetTime();
  DWORD Curr = 0;

  MSG msg = {0};

  timeBeginPeriod(1);

  ZeroMemory(&msg, sizeof(msg));
  while (msg.message != WM_QUIT) {
    if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE)) {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
    } else {
      Curr = timeGetTime();
      if (Curr - Prev >= 1000 / 60) {
        //描画処理
        Prev = Curr;
      }
    }
    Sleep(1);
  }
  timeEndPeriod(1);
}

LRESULT CALLBACK MyApp::WndProc(HWND hWnd, UINT iMsg, WPARAM wParam,
                                LPARAM lParam) {
  switch (iMsg) {
    case WM_ACTIVATE:
      break;
    case WM_DESTROY:
      PostQuitMessage(0);
      hWnd = NULL;
      return 0;
    case WM_SIZE:
      return 0;
    case WM_SYSKEYDOWN:
      switch (wParam) {
        case VK_RETURN:
          return 0;
        case VK_F4:
          PostMessage(hWnd, WM_CLOSE, 0, 0);
          return 0;
        default:
          return 0;
      }
      return 0;
  }
  return DefWindowProc(hWnd, iMsg, wParam, lParam);
}
}  // namespace Test

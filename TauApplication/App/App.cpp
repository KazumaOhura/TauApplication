#include "Include/App.h

namespace Tau {
HINSTANCE App::m_hInstance = nullptr;
Type::tstring App::m_name = _T("");

DWORD GameBase::m_frame = 0;

void GameBase::Run() {
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
      // todo:ゲームの処理
      if (Curr - Prev >= 1000 / 60) {
        this->UpdateLogic();
        this->UpdateRender();
        ++GameBase::m_frame;
      }
      Prev = Curr;
    }
    Sleep(1);
  }
  timeEndPeriod(1);
}

}  // namespace Tau

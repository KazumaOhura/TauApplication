#include "..\Header\GameBase.h"

void Tau::GameBase::Run() {
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
      Prev = Curr;
    }
    Sleep(1);
  }
  timeEndPeriod(1);
}

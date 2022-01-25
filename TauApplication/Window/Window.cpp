#include "Include/Window.h"

namespace Tau {
Window::Window(Type::tstring pWindowName, const HINSTANCE& hInstance,
               Type::RectSize WndSize, WNDPROC WndProc)
    : m_size(WndSize) {
  this->Create(pWindowName, hInstance, WndProc);

  ShowWindow(this->m_hWnd, SW_SHOW);
  UpdateWindow(this->m_hWnd);
}
Window::~Window() {}
HWND Window::Create(Type::tstring pWindowName, const HINSTANCE& hInstance,
                    WNDPROC WndProc) {
  RegisterWindowClass(pWindowName, hInstance, WndProc);
  HWND hWnd = CreateWindow(pWindowName.c_str(), pWindowName.c_str(),
                           WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT,
                           CW_USEDEFAULT, static_cast<int>(m_size.m_width),
                           static_cast<int>(m_size.m_height), NULL, NULL,
                           hInstance, NULL);
  return hWnd;
}
void Window::RegisterWindowClass(Type::tstring pWindowName,
                                 const HINSTANCE& hInstance, WNDPROC WndProc) {
  WNDCLASSEX wndclass;
  wndclass.lpfnWndProc = (WndProc) ? WndProc : DefWindowProc;
  wndclass.lpszClassName = pWindowName.c_str();  // ウィンドウの名前
  wndclass.hInstance = hInstance;
  wndclass.style = CS_HREDRAW | CS_VREDRAW;
  wndclass.hbrBackground =
      static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));  // ウィンドウの背景色
  wndclass.hIcon = wndclass.hIconSm =
      LoadIcon(NULL,
               IDI_APPLICATION);  // todo:独自のアイコンを読み込めるようにする
  wndclass.hCursor =
      LoadCursor(NULL, IDC_ARROW);  // todo:独自のカーソルを読み込めるようにする
  wndclass.lpszMenuName = nullptr;
  wndclass.cbSize = sizeof(wndclass);
  wndclass.cbClsExtra = wndclass.cbWndExtra = 0;
  RegisterClassEx(&wndclass);
}
}  // namespace Tau

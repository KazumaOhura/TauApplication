#ifndef WINDOW_H_
#define WINDOW_H_
#include <Windows.h>
#include <tchar.h>

#include "../Include/RectSize.h"
#include "../Include/TString.h"
namespace Tau {
class Window {
public:
  Window(Type::tstring pWindowName, const HINSTANCE& hInstance,
         Type::RectSize WndSize, WNDPROC WndProc);
  ~Window();

  inline HWND GetHWND() noexcept { return this->m_hWnd; }
  inline Type::RectSize GetSize() noexcept { return this->m_size; }

  Window(const Window&) = delete;
  Window& operator=(const Window&) = delete;

private:
  HWND m_hWnd;
  Type::RectSize m_size;

  HWND Create(Type::tstring pWindowName, const HINSTANCE& hInstance,
              WNDPROC WndProc);
  void RegisterWindowClass(Type::tstring pWindowName,
                           const HINSTANCE& hInstance, WNDPROC WndProc);
};
}  // namespace Tau
#endif

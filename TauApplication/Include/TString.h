#include <tchar.h>

#include <string>
namespace Tau {
namespace Type {
using tstring =
    std::basic_string<TCHAR, std::char_traits<TCHAR>, std::allocator<TCHAR> >;
}  // namespace Type
}  // namespace Tau
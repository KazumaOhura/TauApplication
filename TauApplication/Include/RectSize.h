#ifndef RECTSIZE_H_
#define RECTSIZE_H_
namespace Tau {
namespace Type {
class RectSize {
public:
  inline RectSize(float width, float height)
      : m_width(width), m_height(height) {}
  inline ~RectSize() {}

  float m_width;
  float m_height;
};
}  // namespace Type
}  // namespace Tau
#endif
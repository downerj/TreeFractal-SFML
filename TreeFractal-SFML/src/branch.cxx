#include "branch.hxx"

namespace fractal {
#ifdef DEBUG
  auto operator<<(std::ostream& out, const TreeBranch& branch) -> std::ostream& {
    const auto& [startX, startY, endX, endY, length, angle, depth, color] = branch;
    out << "TreeBranch("
      << "startX=" << startX << ", "
      << "startY=" << startY << ", "
      << "endX=" << endX << ", "
      << "endY=" << endY << ", "
      << "length=" << length << ", "
      << "angle=" << angle << ", "
      << "depth=" << depth << ", "
      << "color=" << color
      << ")";
    return out;
  }
#endif // DEBUG
}

#include "branch.hxx"

namespace fractal {
#ifdef DEBUG
  auto operator<<(std::ostream& out, const TreeBranch& branch) -> std::ostream& {
    out << "TreeBranch("
      << "startX=" << branch.startX << ", "
      << "startY=" << branch.startY << ", "
      << "endX=" << branch.endX << ", "
      << "endY=" << branch.endY << ", "
      << "length=" << branch.length << ", "
      << "angle=" << branch.angle << ", "
      << "depth=" << branch.depth << ", "
      << "color=" << branch.color
      << ")";
    return out;
  }
#endif // DEBUG
}

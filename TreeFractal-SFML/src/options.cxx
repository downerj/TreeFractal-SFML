#include "options.hxx"

namespace fractal {
#ifdef DEBUG
  auto operator<<(std::ostream& out, const TreeBranchOptions& options) -> std::ostream& {
    out << "TreeBranchOptions("
      << "trunkStartX=" << options.trunkStartX << ", "
      << "trunkStartY=" << options.trunkStartY << ", "
      << "trunkLength=" << options.trunkLength << ", "
      << "trunkAngle=" << options.trunkAngle << ", "
      << "lengthRatioCCW=" << options.lengthRatioCCW << ", "
      << "lengthRatioCW=" << options.lengthRatioCW << ", "
      << "maxDepth=" << options.maxDepth << ", "
      << "depthToSwitchColors=" << options.depthToSwitchColors << ", "
      << "deltaAngleCCW=" << options.deltaAngleCCW << ", "
      << "deltaAngleCW=" << options.deltaAngleCW << ", "
      << "branchColor=" << options.branchColor << ", "
      << "leafColor=" << options.leafColor
      << ")";
    return out;
  }
#endif // DEBUG
}

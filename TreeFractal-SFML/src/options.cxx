#include "options.hxx"

namespace fractal {
#ifdef DEBUG
  auto operator<<(std::ostream& out, const TreeBranchOptions& options) -> std::ostream& {
    const auto& [
      trunkStartX, trunkStartY, trunkLength, trunkAngle, lengthRatioCCW, lengthRatioCW, maxDepth,
      depthToSwitchColors, deltaAngleCCW, deltaAngleCW, branchColor, leafColor
    ] = options;
    out << "TreeBranchOptions("
      << "trunkStartX=" << trunkStartX << ", "
      << "trunkStartY=" << trunkStartY << ", "
      << "trunkLength=" << trunkLength << ", "
      << "trunkAngle=" << trunkAngle << ", "
      << "lengthRatioCCW=" << lengthRatioCCW << ", "
      << "lengthRatioCW=" << lengthRatioCW << ", "
      << "maxDepth=" << maxDepth << ", "
      << "depthToSwitchColors=" << depthToSwitchColors << ", "
      << "deltaAngleCCW=" << deltaAngleCCW << ", "
      << "deltaAngleCW=" << deltaAngleCW << ", "
      << "branchColor=" << branchColor << ", "
      << "leafColor=" << leafColor
      << ")";
    return out;
  }
#endif // DEBUG
}

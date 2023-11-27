#ifndef OPTIONS_HXX
#define OPTIONS_HXX

#ifdef DEBUG
#include <iostream>
#endif // DEBUG

namespace fractal {
  struct TreeBranchOptions {
  public:
    const float trunkStartX;
    const float trunkStartY;
    const float trunkLength;
    const float trunkAngle;
    const float lengthRatioCCW;
    const float lengthRatioCW;
    const unsigned int maxDepth;
    const unsigned int depthToSwitchColors;
    const float deltaAngleCCW;
    const float deltaAngleCW;
    const unsigned int branchColor;
    const unsigned int leafColor;

#ifdef DEBUG
    friend auto operator<<(std::ostream& out, const TreeBranchOptions& options) -> std::ostream&;
#endif // DEBUG
  };
}

#endif // OPTIONS_HXX

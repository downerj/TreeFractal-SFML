#ifndef BRANCH_HXX
#define BRANCH_HXX

namespace fractal {
  class TreeBranch {
  public:
    const float startX;
    const float startY;
    const float endX;
    const float endY;
    const float length;
    const float angle;
    const unsigned int depth;
    const unsigned int color;

    TreeBranch() = delete;
  };
}

#endif // BRANCH_HXX

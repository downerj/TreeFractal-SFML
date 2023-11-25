#ifndef BRANCH_HXX
#define BRANCH_HXX

#ifdef DEBUG
#include <iostream>
#endif // DEBUG

namespace fractal {
  struct TreeBranch {
  public:
    const float startX;
    const float startY;
    const float endX;
    const float endY;
    const float length;
    const float angle;
    const unsigned int depth;
    const unsigned int color;

#ifdef DEBUG
    friend auto operator<<(std::ostream& out, const TreeBranch& branch) -> std::ostream&;
#endif // DEBUG
  };
}

#endif // BRANCH_HXX

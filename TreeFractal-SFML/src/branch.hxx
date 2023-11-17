#ifndef BRANCH_HXX
#define BRANCH_HXX

#include <SFML/Graphics.hpp>

namespace fractal {
  class IterateConditions;

  class TreeBranch {
  public:
    const sf::Vector2f start;
    const sf::Vector2f end;
    const float length;
    const float angle;
    const unsigned int depth;

    enum class Direction { CCW, CW };

    TreeBranch() = delete;

    TreeBranch growBranch(Direction direction, const IterateConditions& conditions) const;
  };
}

#endif // BRANCH_HXX

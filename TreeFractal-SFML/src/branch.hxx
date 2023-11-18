#ifndef BRANCH_HXX
#define BRANCH_HXX

#include <SFML/Graphics.hpp>

namespace fractal {
  class TreeBranch {
  public:
    const sf::Vector2f start;
    const sf::Vector2f end;
    const float length;
    const float angle;
    const unsigned int depth;
    const sf::Color color;

    TreeBranch() = delete;
  };
}

#endif // BRANCH_HXX

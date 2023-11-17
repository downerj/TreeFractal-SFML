#ifndef CONDITIONS_HXX
#define CONDITIONS_HXX

#include <cmath>

#include <SFML/Graphics.hpp>

constexpr auto tau = static_cast<float>(M_PI) * 2.f;

namespace fractal {
  class IterateConditions {
  public:
    float branchLengthRatioCCW;
    float branchLengthRatioCW;
    unsigned int maxDepth;
    unsigned int depthToSwitchColors;
    float deltaAngleCCW;
    float deltaAngleCW;
    sf::Color color1;
    sf::Color color2;

    IterateConditions();

    sf::Color getColorByDepth(const unsigned int depth) const;
  };
}

#endif // CONDITIONS_HXX

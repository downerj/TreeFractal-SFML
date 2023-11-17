#include <SFML/Graphics.hpp>

#include "conditions.hxx"

using namespace sf;

namespace fractal {
  IterateConditions::IterateConditions() :
      branchLengthRatioCCW(.6f),
      branchLengthRatioCW(.6f),
      maxDepth(8u),
      depthToSwitchColors(5u),
      deltaAngleCCW(tau / 6.f),
      deltaAngleCW(tau / 6.f) {
    color1 = Color{ 0xffaa00ffu };
    color2 = Color::Green;
  }

  Color IterateConditions::getColorByDepth(const unsigned int depth) const {
    return depth < depthToSwitchColors ? color1 : color2;
  }
}

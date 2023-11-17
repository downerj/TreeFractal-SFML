#ifndef DRAW_HXX
#define DRAW_HXX

#include <vector>

#include <SFML/Graphics.hpp>

namespace fractal {
  class TreeBranch;

  void drawTrees(sf::RenderWindow& window, std::vector<TreeBranch>& branches);
  void redrawWindow(sf::RenderWindow& window, const float windowWidth, const float windowHeight);
}

#endif // DRAW_HXX

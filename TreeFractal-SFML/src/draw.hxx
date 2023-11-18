#ifndef DRAW_HXX
#define DRAW_HXX

#include <vector>

#include <SFML/Graphics.hpp>

namespace fractal {
  class Tree;

  void drawTrees(sf::RenderWindow& window, std::vector<Tree>& trees);
  void redrawWindow(sf::RenderWindow& window, const float windowWidth, const float windowHeight);
}

#endif // DRAW_HXX

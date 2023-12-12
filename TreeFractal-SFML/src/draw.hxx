#ifndef DRAW_HXX
#define DRAW_HXX

#include <SFML/Graphics.hpp>

namespace fractal {
  class Tree;

  class DrawHandler {
  public:
    DrawHandler(sf::RenderWindow& window, const unsigned int windowWidth, const unsigned int windowHeight);
    auto resizeWindow(const unsigned int width, const unsigned int height) -> void;
    auto redraw() -> void;
  private:
    sf::RenderWindow& window;
    unsigned int windowWidth;
    unsigned int windowHeight;
  };
}

#endif // DRAW_HXX

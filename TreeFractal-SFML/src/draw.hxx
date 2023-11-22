#ifndef DRAW_HXX
#define DRAW_HXX

#include <SFML/Graphics.hpp>

namespace fractal {
  class Tree;

  class DrawHandler {
  public:
    DrawHandler(sf::RenderWindow& window, const unsigned int windowWidth, const unsigned int windowHeight);
    void resizeWindow(const unsigned int width, const unsigned int height);
    void redraw();
  private:
    sf::RenderWindow& window;
    unsigned int windowWidth;
    unsigned int windowHeight;
    bool needsRedraw;
  };
}

#endif // DRAW_HXX

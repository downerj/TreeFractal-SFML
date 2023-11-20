#ifndef DRAW_HXX
#define DRAW_HXX

#include <SFML/Graphics.hpp>

namespace fractal {
  class Tree;

  class DrawHandler {
  public:
    DrawHandler(sf::RenderWindow& window, const float windowWidth, const float windowHeight);
    void resizeWindow(const float width, const float height);
    void redraw();
  private:
    sf::RenderWindow& window;
    float windowWidth;
    float windowHeight;
    bool needsRedraw;
  };
}

#endif // DRAW_HXX

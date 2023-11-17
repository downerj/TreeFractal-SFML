#include <algorithm>
#include <array>
#ifdef _WIN32
#define _USE_MATH_DEFINES
#include <math.h>
#else
#include <cmath>
#endif // _WIN32
#include <iostream>
#include <utility>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>

#include "draw.hxx"

using namespace fractal;
using namespace sf;
using namespace std;

int main() {
  auto windowWidth = 600u;
  auto windowHeight = 600u;
  const auto windowMode = VideoMode{ windowWidth, windowHeight };
  constexpr auto windowTitle = "Tree Fractal";

  auto&& window = RenderWindow{ windowMode, windowTitle };
  auto view = window.getDefaultView();
  window.setFramerateLimit(60);

  while (window.isOpen()) {
    auto event = Event();
    while (window.pollEvent(event)) {
      const auto isCtrlPressed = Keyboard::isKeyPressed(Keyboard::LControl) or Keyboard::isKeyPressed(Keyboard::RControl);
      const auto isAltPressed = Keyboard::isKeyPressed(Keyboard::LAlt) or Keyboard::isKeyPressed(Keyboard::RAlt);
      const auto isWPressed = Keyboard::isKeyPressed(Keyboard::W);
      const auto isQPressed = Keyboard::isKeyPressed(Keyboard::Q);
      const auto isF4Pressed = Keyboard::isKeyPressed(Keyboard::F4);
      if ((isCtrlPressed and (isWPressed or isQPressed)) or (isAltPressed and isF4Pressed)) {
        window.close();
        break;
      }
      if (event.type == Event::Closed) {
        window.close();
        break;
      } else if (event.type == Event::Resized) {
        windowWidth = static_cast<float>(event.size.width);
        windowHeight = static_cast<float>(event.size.height);
        view.setSize(windowWidth, windowHeight);
        view.setCenter(windowWidth / 2.f, windowHeight / 2.f);
        window.setView(view);
      }
    }
    redrawWindow(window, windowWidth, windowHeight);
  }

  return 0;
}

#include <algorithm>
#include <array>
#include <iostream>
#include <utility>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>

#include "debug.hxx"
#include "draw.hxx"

using namespace fractal;
using namespace sf;
using namespace std;
using namespace std::literals;

auto main() -> int {
  auto windowWidth = 600u;
  auto windowHeight = 600u;
  const auto windowMode = VideoMode{windowWidth, windowHeight};
  const auto windowTitle = "Tree Fractal"s;

  auto window = RenderWindow{windowMode, windowTitle};
  auto view = window.getDefaultView();
  window.setFramerateLimit(60);
  auto drawHandler = DrawHandler{window, windowWidth, windowHeight};

  while (window.isOpen()) {
    auto event = Event{};
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
        windowWidth = event.size.width;
        windowHeight = event.size.height;
        view.setSize(windowWidth * 1.f, windowHeight * 1.f);
        view.setCenter(windowWidth / 2.f, windowHeight / 2.f);
        window.setView(view);
        drawHandler.resizeWindow(windowWidth, windowHeight);
      }
    }
    drawHandler.redraw();
    window.display();
  }

  return 0;
}

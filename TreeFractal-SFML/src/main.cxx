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

constexpr auto tau = static_cast<float>(M_PI) * 2.f;

class IterateConditions {
public:
  float branchLengthRatio;
  unsigned int maxDepth;
  unsigned int depthToSwitchColors;
  float deltaAngle;
  sf::Color color1;
  sf::Color color2;

  IterateConditions() : branchLengthRatio(.6f), maxDepth(8u), depthToSwitchColors(5u), deltaAngle(tau / 6.f) {
    color1 = sf::Color{ 0xffaa00ffu };
    color2 = sf::Color::Green;
  }

  sf::Color getColorByDepth(const unsigned int depth) const {
    return depth < depthToSwitchColors ? color1 : color2;
  }
};

class TreeBranch {
public:
  const sf::Vector2f start;
  const sf::Vector2f end;
  const float length;
  const float angle;
  const unsigned int depth;

  enum class Direction { LEFT, RIGHT };

  TreeBranch() = delete;

  TreeBranch growBranch(Direction direction, const IterateConditions& conditions) const {
    const auto newStart = end;
    const auto newLength = length * conditions.branchLengthRatio;
    const auto newAngle = angle + (direction == Direction::LEFT ? conditions.deltaAngle : -conditions.deltaAngle);
    const auto newEnd = newStart + sf::Vector2f{ std::cos(newAngle) * newLength, std::sin(newAngle) * newLength };
    const auto newDepth = depth + 1u;
    return { newStart, newEnd, newLength, newAngle, newDepth };
  }
};

void drawTrees(sf::RenderWindow& window, std::vector<TreeBranch>& branches) {
  const auto conditions = IterateConditions();
  while (!branches.empty()) {
    const auto& currentSegment = branches.back();
    branches.pop_back();

    const auto& startColor = conditions.getColorByDepth(currentSegment.depth);
    const auto& endColor = startColor;
    const auto line = std::array<sf::Vertex, 2u>{
      sf::Vertex{ currentSegment.start, startColor },
      sf::Vertex{ currentSegment.end, endColor }
    };

    window.draw(line.data(), 2u, sf::PrimitiveType::Lines);

    if (currentSegment.depth < conditions.maxDepth) {
      const auto& branchLeft = currentSegment.growBranch(TreeBranch::Direction::LEFT, conditions);
      const auto& branchRight = currentSegment.growBranch(TreeBranch::Direction::RIGHT, conditions);
      branches.push_back(branchLeft);
      branches.push_back(branchRight);
    }
  }
}

void redraw(sf::RenderWindow& window, const float windowWidth, const float windowHeight) {
  window.clear(sf::Color::Black);

  const auto trunkStart = sf::Vector2f{ windowWidth / 2.f, windowHeight / 2.f };
  constexpr auto numTrees = 3u;
  const auto initialLength = std::min(windowWidth, windowHeight) / 6.f;
  constexpr auto trunkDeltaAngle = tau / numTrees;
  auto branches = std::vector<TreeBranch>();
  for (auto t = 0u; t < numTrees; t++) {
    const auto angle = -tau / 4.f + trunkDeltaAngle * t;
    const auto trunkEnd = trunkStart + sf::Vector2f{
      std::cos(angle) * initialLength,
      std::sin(angle) * initialLength
    };
    branches.push_back({
      trunkStart,
      trunkEnd,
      initialLength,
      angle,
      0u
    });
  }
  drawTrees(window, branches);

  window.display();
}

int main() {
  auto windowWidth = 600u;
  auto windowHeight = 600u;
  const auto windowMode = sf::VideoMode{ windowWidth, windowHeight };
  constexpr auto windowTitle = "Tree Fractal";

  auto&& window = sf::RenderWindow{ windowMode, windowTitle };
  auto view = window.getDefaultView();
  window.setFramerateLimit(60);

  while (window.isOpen()) {
    auto event = sf::Event();
    while (window.pollEvent(event)) {
      const auto isCtrlPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) or sf::Keyboard::isKeyPressed(sf::Keyboard::RControl);
      const auto isAltPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::LAlt) or sf::Keyboard::isKeyPressed(sf::Keyboard::RAlt);
      const auto isWPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
      const auto isQPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
      const auto isF4Pressed = sf::Keyboard::isKeyPressed(sf::Keyboard::F4);
      if ((isCtrlPressed and (isWPressed or isQPressed)) or (isAltPressed and isF4Pressed)) {
        window.close();
        break;
      }
      if (event.type == sf::Event::Closed) {
        window.close();
        break;
      } else if (event.type == sf::Event::Resized) {
        windowWidth = static_cast<float>(event.size.width);
        windowHeight = static_cast<float>(event.size.height);
        view.setSize(windowWidth, windowHeight);
        view.setCenter(windowWidth / 2.f, windowHeight / 2.f);
        window.setView(view);
      }
    }
    redraw(window, windowWidth, windowHeight);
  }

  return 0;
}

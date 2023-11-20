#include "branch.hxx"
#include "debug.hxx"
#include "draw.hxx"
#include "math.hxx"
#include "tree.hxx"

using namespace sf;
using namespace std;

namespace fractal {
  DrawHandler::DrawHandler(sf::RenderWindow& window, const float windowWidth, const float windowHeight) :
      window(window),
      windowWidth(windowWidth),
      windowHeight(windowHeight),
      needsRedraw(true) {}

  void DrawHandler::resizeWindow(const float width, const float height) {
    if (width == windowWidth and height == windowHeight) {
      return;
    }
    windowWidth = width;
    windowHeight = height;
    needsRedraw = true;
  }

  void DrawHandler::redraw() {
    if (not needsRedraw) {
      return;
    }

    std::vector<Tree> trees;
    const auto trunkStartX = windowWidth / 2.f;
    const auto trunkStartY = windowHeight / 2.f;
    constexpr auto numTrees = 3u;
    const auto trunkLength = min(windowWidth, windowHeight) / 6.f;
    constexpr auto trunkDeltaAngle = tau / numTrees;
    for (auto t = 0u; t < numTrees; t++) {
      const auto trunkAngle = -tau / 4.f + trunkDeltaAngle * t;
      trees.push_back(Tree(trunkStartX, trunkStartY, trunkLength, trunkAngle));
    }

    window.clear(Color::Black);

    for (auto& tree : trees) {
      for (const auto& branch : tree) {
        const auto line = array<Vertex, 2u>{
          Vertex{ branch.start, branch.color },
          Vertex{ branch.end, branch.color }
        };
        window.draw(line.data(), 2u, PrimitiveType::Lines);
      }
    }
    needsRedraw = false;
  }
}

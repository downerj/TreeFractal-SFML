#include "branch.hxx"
#include "debug.hxx"
#include "draw.hxx"
#include "math.hxx"
#include "tree.hxx"

using namespace sf;
using namespace std;

namespace fractal {
  DrawHandler::DrawHandler(RenderWindow& window, const unsigned int windowWidth, const unsigned int windowHeight) :
      window(window),
      windowWidth(windowWidth),
      windowHeight(windowHeight),
      needsRedraw(true) {}

  void DrawHandler::resizeWindow(const unsigned int width, const unsigned int height) {
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

    vector<Tree> trees;
    const auto trunkStartX = windowWidth / 2.f;
    const auto trunkStartY = windowHeight;
    constexpr auto numTrees = 1u;
    const auto trunkLength = min(windowWidth, windowHeight) / 6.f;
    constexpr auto trunkDeltaAngle = 360.f / numTrees;
    for (auto t = 0u; t < numTrees; t++) {
      const auto trunkAngle = -90.f + trunkDeltaAngle * t;
      auto tree = Tree(trunkStartX, trunkStartY, trunkLength, trunkAngle);
      tree.deltaAngleCW = 30.f;
      tree.deltaAngleCCW = tree.deltaAngleCW;
      tree.branchLengthRatioCW = .8f;
      tree.branchLengthRatioCCW = tree.branchLengthRatioCW;
      tree.maxDepth = 11u;
      tree.depthToSwitchColors = 7u;
      trees.push_back(tree);
    }

    window.clear(Color::Black);

    for (auto& tree : trees) {
      for (const auto& branch : tree) {
        const auto start = Vector2f{ branch.startX, branch.startY };
        const auto end = Vector2f{ branch.endX, branch.endY };
        const auto color = Color(branch.color);
        const auto line = array<Vertex, 2u>{
          Vertex{ start, color },
          Vertex{ end, color }
        };
        window.draw(line.data(), 2u, PrimitiveType::Lines);
      }
    }
    needsRedraw = false;
  }
}

#include <forward_list>

#include "branch.hxx"
#include "debug.hxx"
#include "draw.hxx"
#include "math.hxx"
#include "options.hxx"
#include "tree.hxx"

using namespace sf;
using namespace std;

namespace fractal {
  DrawHandler::DrawHandler(RenderWindow& window, const unsigned int windowWidth, const unsigned int windowHeight) :
      window(window),
      windowWidth(windowWidth),
      windowHeight(windowHeight),
      needsRedraw(true) {}

  auto DrawHandler::resizeWindow(const unsigned int width, const unsigned int height) -> void {
    if (width == windowWidth and height == windowHeight) {
      return;
    }
    windowWidth = width;
    windowHeight = height;
    needsRedraw = true;
  }

  auto DrawHandler::redraw() -> void {
    if (not needsRedraw) {
      return;
    }

    const auto trunkLength = min(windowWidth, windowHeight) / 6.f;
    constexpr auto initialAngle = -90.f;
    constexpr auto treeCount = 3u;
    constexpr auto trunkDeltaAngle = 360.f / treeCount;
    const auto trunkStartX = windowWidth / 2.f;
    const auto trunkStartY = windowHeight / 2.f;

    auto trees = forward_list<Tree>();
    for (auto t = 0u; t < treeCount; ++t) {
      const auto trunkAngle = initialAngle + trunkDeltaAngle * t;
      constexpr auto deltaAngleCW = 60.f;
      constexpr auto deltaAngleCCW = deltaAngleCW;
      constexpr auto lengthRatioCW = .6f;
      constexpr auto lengthRatioCCW = lengthRatioCW;
      constexpr auto maxDepth = 11u;
      constexpr auto depthToSwitchColors = 7u;
      constexpr auto branchColor = 0xffaa00ffu;
      constexpr auto leafColor = 0x00ff00ffu;
      const auto branchOptions = TreeBranchOptions{
        trunkStartX,
        trunkStartY,
        trunkLength,
        trunkAngle,
        lengthRatioCCW,
        lengthRatioCW,
        maxDepth,
        depthToSwitchColors,
        deltaAngleCCW,
        deltaAngleCW,
        branchColor,
        leafColor
      };
      const auto tree = Tree(branchOptions);
      trees.emplace_front(tree);
    }

    window.clear(Color::Black);

    for (const auto& tree : trees) {
      for (const auto& branch : tree.branches) {
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

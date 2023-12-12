#include <forward_list>
#include <ranges>

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
      window{window},
      windowWidth{windowWidth},
      windowHeight{windowHeight} {}

  auto DrawHandler::resizeWindow(const unsigned int width, const unsigned int height) -> void {
    if (width == windowWidth and height == windowHeight) {
      return;
    }
    windowWidth = width;
    windowHeight = height;
  }

  auto DrawHandler::redraw() -> void {
    constexpr auto initialAngle = -90.f;
    constexpr auto treeCount = 3u;
    constexpr auto trunkDeltaAngle = 360.f / treeCount;
    auto trees = forward_list<Tree>{};
    for (const auto t : views::iota(0u, treeCount)) {
      const auto branchOptions = TreeBranchOptions{
        .trunkStartX = windowWidth / 2.f,
        .trunkStartY = windowHeight / 2.f,
        .trunkLength = min(windowWidth, windowHeight) / 6.f,
        .trunkAngle = initialAngle + trunkDeltaAngle * t,
        .lengthRatioCCW = .6f,
        .lengthRatioCW = .6f,
        .maxDepth = 11u,
        .depthToSwitchColors = 7u,
        .deltaAngleCCW = 60.f,
        .deltaAngleCW = 60.f,
        .branchColor = 0xffaa00ffu,
        .leafColor = 0x00ff00ffu
      };
      const auto tree = Tree{branchOptions};
      trees.emplace_front(tree);
    }

    window.clear(Color::Black);

    for (const auto& tree : trees) {
      for (const auto& branch : tree.branches) {
        const auto start = Vector2f{branch.startX, branch.startY};
        const auto end = Vector2f{branch.endX, branch.endY};
        const auto drawColor = Color{branch.color};
        const auto line = array<Vertex, 2u>{
          Vertex{start, drawColor},
          Vertex{end, drawColor}
        };
        window.draw(line.data(), 2u, PrimitiveType::Lines);
      }
    }
  }
}

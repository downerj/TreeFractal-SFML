#include "branch.hxx"
#include "conditions.hxx"
#include "draw.hxx"
#include "math.hxx"

using namespace sf;
using namespace std;

namespace fractal {
  void drawTrees(RenderWindow& window, vector<TreeBranch>& branches) {
    using Direction = TreeBranch::Direction;

    const auto conditions = IterateConditions();
    while (!branches.empty()) {
      const auto& currentSegment = branches.back();
      branches.pop_back();

      const auto& startColor = conditions.getColorByDepth(currentSegment.depth);
      const auto& endColor = startColor;
      const auto line = array<Vertex, 2u>{
        Vertex{ currentSegment.start, startColor },
        Vertex{ currentSegment.end, endColor }
      };

      window.draw(line.data(), 2u, PrimitiveType::Lines);

      if (currentSegment.depth < conditions.maxDepth) {
        const auto& branchLeft = currentSegment.growBranch(Direction::CCW, conditions);
        const auto& branchRight = currentSegment.growBranch(Direction::CW, conditions);
        branches.push_back(branchLeft);
        branches.push_back(branchRight);
      }
    }
  }

  void redrawWindow(RenderWindow& window, const float windowWidth, const float windowHeight) {
    window.clear(Color::Black);

    const auto trunkStart = Vector2f{ windowWidth / 2.f, windowHeight / 2.f };
    constexpr auto numTrees = 3u;
    const auto initialLength = min(windowWidth, windowHeight) / 6.f;
    constexpr auto trunkDeltaAngle = tau / numTrees;
    auto branches = vector<TreeBranch>();
    for (auto t = 0u; t < numTrees; t++) {
      const auto angle = -tau / 4.f + trunkDeltaAngle * t;
      const auto trunkEnd = trunkStart + Vector2f{
        cos(angle) * initialLength,
        sin(angle) * initialLength
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
}

#include "branch.hxx"
#include "debug.hxx"
#include "draw.hxx"
#include "math.hxx"
#include "tree.hxx"

using namespace sf;
using namespace std;

namespace fractal {
  void drawTrees(RenderWindow& window, vector<Tree>& trees) {
    for (auto& tree : trees) {
      for (const auto& branch : tree) {
        const auto line = array<Vertex, 2u>{
          Vertex{ branch.start, branch.color },
          Vertex{ branch.end, branch.color }
        };
        window.draw(line.data(), 2u, PrimitiveType::Lines);
      }
    }
  }

  void redrawWindow(RenderWindow& window, const float windowWidth, const float windowHeight) {
    window.clear(Color::Black);

    const auto trunkStartX = windowWidth / 2.f;
    const auto trunkStartY = windowHeight / 2.f;
    constexpr auto numTrees = 3u;
    const auto trunkLength = min(windowWidth, windowHeight) / 6.f;
    constexpr auto trunkDeltaAngle = tau / numTrees;
    auto trees = vector<Tree>();
    for (auto t = 0u; t < numTrees; t++) {
      const auto trunkAngle = -tau / 4.f + trunkDeltaAngle * t;
      trees.push_back(Tree(trunkStartX, trunkStartY, trunkLength, trunkAngle));
    }
    drawTrees(window, trees);

    window.display();
  }
}

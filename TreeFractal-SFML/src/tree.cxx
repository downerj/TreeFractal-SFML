#include <queue>
#include <tuple>

#include "branch.hxx"
#include "debug.hxx"
#include "tree.hxx"

using namespace std;

namespace fractal {
  Tree::Tree(const TreeBranchOptions& branchOptions) : branchOptions(branchOptions) {
    auto workBranches = queue<TreeBranch>();
    const auto trunk = makeTrunk();
    workBranches.push(trunk);
    while (workBranches.front().depth < branchOptions.maxDepth) {
      const auto& branch = workBranches.front();
      const auto leftChild = growChild(branch, Direction::CCW);
      const auto rightChild = growChild(branch, Direction::CW);
      workBranches.push(leftChild);
      workBranches.push(rightChild);
      workBranches.pop();
      branches.emplace_front(branch);
    }
    while (not workBranches.empty()) {
      const auto& branch = workBranches.front();
      workBranches.pop();
      branches.emplace_front(branch);
    }
  }

  auto Tree::makeTrunk() const -> TreeBranch {
    const auto endX = branchOptions.trunkStartX + cosf(branchOptions.trunkAngle * degToRad) * branchOptions.trunkLength;
    const auto endY = branchOptions.trunkStartY + sinf(branchOptions.trunkAngle * degToRad) * branchOptions.trunkLength;
    const auto depth = 0u;
    const auto trunk = TreeBranch{
      branchOptions.trunkStartX,
      branchOptions.trunkStartY,
      endX,
      endY,
      branchOptions.trunkLength,
      branchOptions.trunkAngle,
      depth,
      branchOptions.branchColor
    };
    return trunk;
  }

  auto Tree::growChild(const TreeBranch& branch, const Direction direction) const -> TreeBranch {
    const auto newStartX = branch.endX;
    const auto newStartY = branch.endY;
    const auto newLength = branch.length * (direction == Direction::CCW ? branchOptions.lengthRatioCCW : branchOptions.lengthRatioCW);
    const auto newAngle = branch.angle + (direction == Direction::CCW ? -branchOptions.deltaAngleCCW : branchOptions.deltaAngleCW);
    const auto newEndX = newStartX + cosf(newAngle * degToRad) * newLength;
    const auto newEndY = newStartY + sinf(newAngle * degToRad) * newLength;
    const auto newDepth = branch.depth + 1u;
    const auto newColor = newDepth < branchOptions.depthToSwitchColors ? branchOptions.branchColor : branchOptions.leafColor;
    return { newStartX, newStartY, newEndX, newEndY, newLength, newAngle, newDepth, newColor };
  }
}

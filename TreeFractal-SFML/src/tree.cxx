#include <queue>
#include <tuple>

#include "branch.hxx"
#include "debug.hxx"
#include "tree.hxx"

using namespace std;

namespace fractal {
  Tree::Tree(const TreeBranchOptions& branchOptions) : branchOptions{branchOptions} {
    auto workBranches = queue<TreeBranch>{};
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
    const auto trunk = TreeBranch{
      .startX = branchOptions.trunkStartX,
      .startY = branchOptions.trunkStartY,
      .endX = branchOptions.trunkStartX + cosf(branchOptions.trunkAngle * degToRad) * branchOptions.trunkLength,
      .endY = branchOptions.trunkStartY + sinf(branchOptions.trunkAngle * degToRad) * branchOptions.trunkLength,
      .length = branchOptions.trunkLength,
      .angle = branchOptions.trunkAngle,
      .depth = 0u,
      .color = branchOptions.branchColor
    };
    return trunk;
  }

  auto Tree::growChild(const TreeBranch& branch, const Direction direction) const -> TreeBranch {
    const auto newLength = branch.length * (direction == Direction::CCW ? branchOptions.lengthRatioCCW : branchOptions.lengthRatioCW);
    const auto newAngle = branch.angle + (direction == Direction::CCW ? -branchOptions.deltaAngleCCW : branchOptions.deltaAngleCW);
    const auto newDepth = branch.depth + 1u;
    return {
      .startX = branch.endX,
      .startY = branch.endY,
      .endX = branch.endX + cosf(newAngle * degToRad) * newLength,
      .endY = branch.endY + sinf(newAngle * degToRad) * newLength,
      .length = newLength,
      .angle = newAngle,
      .depth = newDepth,
      .color = newDepth < branchOptions.depthToSwitchColors ? branchOptions.branchColor : branchOptions.leafColor
    };
  }
}

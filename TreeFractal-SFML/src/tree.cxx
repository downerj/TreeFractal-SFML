#include "branch.hxx"
#include "tree.hxx"

namespace fractal {
  Tree::Tree(float trunkX, float trunkY, float trunkLength, float trunkAngle) :
    trunkStartX(trunkX),
    trunkStartY(trunkY),
    trunkLength(trunkLength),
    trunkAngle(trunkAngle),
    branchLengthRatioCCW(.6f),
    branchLengthRatioCW(.6f),
    maxDepth(8u),
    depthToSwitchColors(5u),
    deltaAngleCCW(tau / 6.f),
    deltaAngleCW(tau / 6.f),
    branchColor(0xffaa00ffu),
    leafColor(0x00ff00ffu),
    endIt(Iterator(*this)) {}

  Tree::Iterator::Iterator(Tree& tree) : tree(tree), isEnd(true) {}
  Tree::Iterator& Tree::Iterator::operator++() {
    if (not tree.branches.empty() and tree.branches.front().depth < tree.maxDepth) {
      tree.replaceBranchWithChildren();
    } else {
      isEnd = true;
    }
    return *this;
  }
  TreeBranch& Tree::Iterator::operator*() {
    return tree.branches.front();
  }
  const TreeBranch& Tree::Iterator::operator*() const {
    return tree.branches.front();
  }

  Tree::Iterator Tree::begin() {
    while (not branches.empty()) {
      branches.pop();
    }
    makeTrunk();
    auto it = Tree::Iterator(*this);
    it.isEnd = false;
    return it;
  }
  Tree::Iterator Tree::end() { return endIt; }

  void Tree::makeTrunk() {
    const auto trunkEndX = trunkStartX + static_cast<float>(cos(trunkAngle)) * trunkLength;
    const auto trunkEndY = trunkStartY + static_cast<float>(sin(trunkAngle)) * trunkLength;
    const auto trunkDepth = 0u;
    const auto trunk = TreeBranch{
      trunkStartX,
      trunkStartY,
      trunkEndX,
      trunkEndY,
      trunkLength,
      trunkAngle,
      trunkDepth,
      branchColor
    };
    branches.push(trunk);
  }

  void Tree::replaceBranchWithChildren() {
    if (branches.empty()) {
      return;
    }
    const auto branch = branches.front();
    branches.pop();
    for (const auto direction : { Direction::CCW, Direction::CW }) {
      const auto newStartX = branch.endX;
      const auto newStartY = branch.endY;
      const auto newLength = branch.length * (direction == Direction::CCW ? branchLengthRatioCCW : branchLengthRatioCW);
      const auto newAngle = branch.angle + (direction == Direction::CCW ? -deltaAngleCCW : deltaAngleCW);
      const auto newEndX = newStartX + static_cast<float>(cos(newAngle)) * newLength;
      const auto newEndY = newStartY + static_cast<float>(sin(newAngle)) * newLength;
      const auto newDepth = branch.depth + 1u;
      const auto newColor = newDepth < depthToSwitchColors ? branchColor : leafColor;
      const auto newBranch = TreeBranch{ newStartX, newStartY, newEndX, newEndY, newLength, newAngle, newDepth, newColor };
      branches.push(newBranch);
    }
  }

  bool operator!=(const fractal::Tree::Iterator& lhs, const fractal::Tree::Iterator& rhs) {
    return not lhs.isEnd or not rhs.isEnd;
  }
}

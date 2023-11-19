#include <iostream>

#include <SFML/Graphics.hpp>

#include "branch.hxx"
#include "tree.hxx"

using namespace sf;

namespace fractal {
  Tree::Tree(float trunkX, float trunkY, float trunkLength, float trunkAngle) :
    trunkStart(Vector2f(trunkX, trunkY)),
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
    if (!tree.branches.empty() and tree.branches.front().depth < tree.maxDepth) {
      tree.replaceBranchWithChildren();
    } else {
      isEnd = true;
    }
    return *this;
  }
  bool Tree::Iterator::operator!=(const Iterator& rhs) const {
    return !(isEnd and rhs.isEnd);
  }
  TreeBranch& Tree::Iterator::operator*() {
    return tree.branches.front();
  }
  const TreeBranch& Tree::Iterator::operator*() const {
    return tree.branches.front();
  }

  Tree::Iterator Tree::begin() {
    if (branches.empty()) {
      makeTrunk();
    }
    auto it = Tree::Iterator(*this);
    it.isEnd = false;
    return it;
  }
  Tree::Iterator Tree::end() { return endIt; }

  void Tree::makeTrunk() {
    const auto trunkEnd = trunkStart + Vector2f{
      static_cast<float>(cos(trunkAngle)) * trunkLength,
      static_cast<float>(sin(trunkAngle)) * trunkLength
    };
    const auto trunkDepth = 0u;
    const auto trunk = TreeBranch{
      trunkStart,
      trunkEnd,
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
      const auto newStart = branch.end;
      const auto newLength = branch.length * (direction == Direction::CCW ? branchLengthRatioCCW : branchLengthRatioCW);
      const auto newAngle = branch.angle + (direction == Direction::CCW ? -deltaAngleCCW : deltaAngleCW);
      const auto newEnd = newStart + Vector2f{
        static_cast<float>(cos(newAngle)) * newLength,
        static_cast<float>(sin(newAngle)) * newLength
      };
      const auto newDepth = branch.depth + 1u;
      const auto newColor = newDepth < depthToSwitchColors ? branchColor : leafColor;
      const auto newBranch = TreeBranch{ newStart, newEnd, newLength, newAngle, newDepth, newColor };
      branches.push(newBranch);
    }
  }
}

#include <cmath>

#include "conditions.hxx"
#include "branch.hxx"

using namespace sf;
using namespace std;

namespace fractal {
  TreeBranch TreeBranch::growBranch(TreeBranch::Direction direction, const IterateConditions& conditions) const {
    const auto newStart = end;
    const auto newLength = length * (direction == Direction::CCW ? conditions.branchLengthRatioCCW : conditions.branchLengthRatioCW);
    const auto newAngle = angle + (direction == Direction::CCW ? -conditions.deltaAngleCCW : conditions.deltaAngleCW);
    const auto newEnd = newStart + Vector2f{ cos(newAngle) * newLength, sin(newAngle) * newLength };
    const auto newDepth = depth + 1u;
    return { newStart, newEnd, newLength, newAngle, newDepth };
  }
}

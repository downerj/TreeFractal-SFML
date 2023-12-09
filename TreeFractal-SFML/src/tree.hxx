#ifndef TREE_HXX
#define TREE_HXX

#include <forward_list>

#include "branch.hxx"
#include "options.hxx"
#include "math.hxx"

namespace fractal {
  class TreeBranch;

  class Tree {
  public:
    Tree(const TreeBranchOptions&);
    std::forward_list<TreeBranch> branches;
  private:
    const TreeBranchOptions& branchOptions;
    enum class Direction {CCW, CW};
    auto makeTrunk() const -> TreeBranch;
    auto growChild(const TreeBranch&, const Direction) const -> TreeBranch;
  };
}

#endif // TREE_HXX

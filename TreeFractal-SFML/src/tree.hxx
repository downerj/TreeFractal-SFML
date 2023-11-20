#ifndef TREE_HXX
#define TREE_HXX

#include <queue>

#include "branch.hxx"
#include "math.hxx"

namespace fractal {
  class TreeBranch;

  class Tree {
  public:
    float trunkStartX;
    float trunkStartY;
    float trunkLength;
    float trunkAngle;
    float branchLengthRatioCCW;
    float branchLengthRatioCW;
    unsigned int maxDepth;
    unsigned int depthToSwitchColors;
    float deltaAngleCCW;
    float deltaAngleCW;
    unsigned int branchColor;
    unsigned int leafColor;

    Tree(float trunkX, float trunkY, float trunkLength, float trunkAngle);

    friend class Iterator;
    class Iterator {
    public:
      Iterator(Tree&);
      Iterator& operator++();
      friend bool operator!=(const Iterator&, const Iterator&);
      TreeBranch& operator*();
      const TreeBranch& operator*() const;
    private:
      friend class Tree;
      Tree& tree;
      bool isEnd;
    };

    Iterator begin();
    Iterator end();

  private:
    enum class Direction { CCW, CW };
    Iterator endIt;
    std::queue<TreeBranch> branches;
    void makeTrunk();
    void replaceBranchWithChildren();
  };
}

#endif // TREE_HXX

#ifndef TREE_HXX
#define TREE_HXX

#include <queue>

#include <SFML/Graphics.hpp>

#include "math.hxx"

namespace fractal {
  class TreeBranch;

  class Tree {
  public:
    sf::Vector2f trunkStart;
    float trunkLength;
    float trunkAngle;
    float branchLengthRatioCCW;
    float branchLengthRatioCW;
    unsigned int maxDepth;
    unsigned int depthToSwitchColors;
    float deltaAngleCCW;
    float deltaAngleCW;
    sf::Color branchColor;
    sf::Color leafColor;

    Tree(float trunkX, float trunkY, float trunkLength, float trunkAngle);

    friend class Iterator;
    class Iterator {
    public:
      Iterator(Tree&);
      Iterator& operator++();
      bool operator!=(const Iterator&) const;
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

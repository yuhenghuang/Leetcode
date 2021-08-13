#define QUAD_NODE
#define _DELETE_RETURN_POINTER
#include "utils3.hpp"

class Solution {
  private:
    Node* generateNode(Node* n1, Node* n2, Node* n3, Node* n4) {
      // if we can combine n1 ~ n4 to a single node
      if (n1->isLeaf && n2->isLeaf && n3->isLeaf && n4->isLeaf &&
          n1->val == n2->val && n2->val == n3->val && n3->val == n4->val) {
        Node* node = new Node(n1->val, true);
        delete n1; delete n2; delete n3; delete n4;
        return node;
      }

      return new Node(true, false, n1, n2, n3, n4);
    }

  public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
      if (!quadTree1 && !quadTree2)
        return nullptr;

      if (!quadTree1 || !quadTree2) {
        Node* node = quadTree1 ? quadTree1 : quadTree2;

        return node->isLeaf ? new Node(*node) : new Node(
          true, false,
          intersect(node->topLeft, nullptr),
          intersect(node->topRight, nullptr),
          intersect(node->bottomLeft, nullptr),
          intersect(node->bottomRight, nullptr)
        );
      }
      else {
        if ((quadTree1->isLeaf && quadTree1->val) || (quadTree2->isLeaf && quadTree2->val))
          return new Node(true, true);
        else if (quadTree1->isLeaf && quadTree2->isLeaf)
          return new Node(quadTree1->val | quadTree2->val, true);
        else
          return generateNode(
            intersect(quadTree1->topLeft, quadTree2->topLeft),
            intersect(quadTree1->topRight, quadTree2->topRight),
            intersect(quadTree1->bottomLeft, quadTree2->bottomLeft),
            intersect(quadTree1->bottomRight, quadTree2->bottomRight)
          );
      }
    }
};


int main() {
  UFUNCS(Solution::intersect);
  return 0;
}
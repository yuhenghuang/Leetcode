#ifndef _DS_H
#define _DS_H


struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#ifdef PERFECT_BINARY_TREE_NODE

class Node {
  public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

#endif // end of PERFECT_BINARY_TREE_NODE


#ifdef RANDOM_POINTER

class Node {
  public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val): val(_val), next(nullptr), random(nullptr) { }
};

#endif // end of RANDOM_POINTER

#include <vector>

#ifdef NARY_NODE

class Node {
  public:
    int val;

#ifdef NARY_TREE_NODE
    std::vector<Node*> children;
#else
    std::vector<Node*> neighbors;
#endif

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*>& nodes) {
        val = _val;
#ifdef NARY_TREE_NODE
        children = nodes;
#else
        neighbors = nodes;
#endif
    }
};

#endif // end of NARY_NODE

#endif // end of _DS_H

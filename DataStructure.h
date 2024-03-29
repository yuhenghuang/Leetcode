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


// class Node;

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

#if defined(NARY_TREE_NODE) || defined(NARY_GRAPH_NODE)

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

#endif // end of NARY_TREE_NODE or NARY_GRAPH_NODE


#ifdef QUAD_NODE

class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};

#endif // end of QUAD_NODE


#ifdef CIRCULAR_LINKED_NODE

class Node {
public:
  int val;
  Node* next;
  
  Node() {}

  Node(int _val) {
    val = _val;
    next = NULL;
  }

  Node(int _val, Node* _next) {
    val = _val;
    next = _next;
  }
};

#endif // end of CIRCULAR_LINKED_NODE

class NestedInteger {
  private:
    bool is_integer;
    int val;
    std::vector<NestedInteger> data;

  public:
    // Constructor initializes an empty nested list.
    NestedInteger(): is_integer(false) { }

    // Constructor initializes a single integer.
    NestedInteger(int value): is_integer(true), val(value) { }

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const { return is_integer; }

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const { return val; }

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value) {
      val = value;
      if (!is_integer) {
        is_integer = true;
        data.clear();
      }
    }

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni) {
      is_integer = false;
      data.push_back(ni);
    }

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const std::vector<NestedInteger> &getList() const { return data; }
};

#endif // end of _DS_H

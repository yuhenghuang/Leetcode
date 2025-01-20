#include <local_leetcode.hpp>

/**
 * @brief unidirectional tree iterator. from leftmost to rightmost, or reverse
 * 
 * @tparam L pointer to class member variable, either left or right
 * @tparam R pointer to class member variable, the opposite of L
 * @tparam M maximum value of iteration given L, INT_MAX if left, INT_MIN if right
 * 
 */
template <
  TreeNode* TreeNode::* L,
  TreeNode* TreeNode::* R = (L == &TreeNode::left) ? &TreeNode::right : &TreeNode::left,
  int M = (L == &TreeNode::left) ? INT_MAX : INT_MIN
>
class TreeIterator {
  private:
    stack<TreeNode*> s;

    void pushNodes(TreeNode* root) {
      while (root) {
        s.push(root);
        root = root->*L;
      }
    }

  public:
    TreeIterator(TreeNode* root) {
      pushNodes(root);
    }

    TreeIterator& operator++() {
      if (!s.empty()) {
        TreeNode* root = s.top();
        s.pop();
        pushNodes(root->*R);
      }
      // call operator*;
      return *this;
    }

    int operator*() {
      return s.empty() ? M : s.top()->val;
    }
};

// inorder iteration
typedef TreeIterator<&TreeNode::left> tree_iterator;
// reverse inorder iteration
typedef TreeIterator<&TreeNode::right> tree_reverse_iterator;

class Solution {
  public:
    bool findTarget(TreeNode* root, int k) {
      // iterator over tree (left -> right)
      tree_iterator p(root);
      // reverse iterator (right -> left)
      tree_reverse_iterator q(root);

      while (*p < *q) {
        int sum = *p + *q;
        if (sum < k)
          ++p;
        else if (sum > k)
          ++q;
        else
          return true;
      }

      return false;
    }
};


int main() {
  EXECS(Solution::findTarget);
  return 0;
}

#include "utils3.hpp"

class BSTIterator {
  private:
    int i;
    vector<int> vals;

  public:
    BSTIterator(TreeNode* root): i(0) {
      vals.push_back(-1);

      stack<TreeNode*> s;
      while (root || !s.empty()) {
        while (root) {
          s.push(root);
          root = root->left;
        }

        root = s.top();
        s.pop();

        vals.push_back(root->val);
        root = root->right;
      }

    }

    bool hasNext() {
      return i + 1 < vals.size();
    }

    int next() {
      return vals[++i];
    }

    bool hasPrev() {
      return i > 0;
    }

    int prev() {
      return vals[--i];
    }
};


int main() {
  UFUNCX(
    CTOR(TreeNode*),
    &BSTIterator::hasNext,
    &BSTIterator::next,
    &BSTIterator::hasPrev,
    &BSTIterator::prev
  );
  return 0;
}
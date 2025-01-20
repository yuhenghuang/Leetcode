#include <local_leetcode.hpp>

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


// lazily flatten the tree
class BSTIteratorLazy {
  private:
    int i;
    vector<int> vec;
    stack<TreeNode*> s;

    void pushLeft(TreeNode* root) {
      while (root) {
        s.push(root);
        root = root->left;
      }
    }

  public:
    BSTIteratorLazy(TreeNode* root): i(-1) {
      pushLeft(root);
    }

    bool hasNext() { return i + 1 < vec.size() || !s.empty(); }

    int next() {
      if (i + 1 < vec.size())
        return vec[++i];
      else {
        TreeNode* root = s.top();
        s.pop();

        vec.push_back(root->val);

        ++i;
        pushLeft(root->right);

        return root->val;
      }
    }

    bool hasPrev() { return i > 0; }
    int prev() { return vec[--i]; }
};


int main() {
  EXECX(
    CTOR(TreeNode*),
    &BSTIterator::hasNext,
    &BSTIterator::next,
    &BSTIterator::hasPrev,
    &BSTIterator::prev
  );

  EXECX(
    CTOR(TreeNode*),
    &BSTIteratorLazy::hasNext,
    &BSTIteratorLazy::next,
    &BSTIteratorLazy::hasPrev,
    &BSTIteratorLazy::prev
  );
  return 0;
}
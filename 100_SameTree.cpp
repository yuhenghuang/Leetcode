#include <local_leetcode.hpp>

class BFSIterator {
  private:
    queue<TreeNode*> q;

  public:
    BFSIterator(TreeNode* root) {
      q.push(root);
    }

    TreeNode* next() {
      TreeNode* root = q.front();
      q.pop();
      if (root) {
        q.push(root->left);
        q.push(root->right);
      }

      return root;
    }

    bool hasNext() const {
      return !q.empty();
    }
};


class Solution {
  private:
    bool equal(TreeNode* p, TreeNode* q) const {
      if (p == nullptr && q == nullptr)
        return true;

      return p && q && p->val == q->val;
    }

  public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
      BFSIterator p1(p), p2(q);

      while (p1.hasNext() && p2.hasNext()) {
        if (!equal(p1.next(), p2.next()))
          return false;
      }

      return true;
    }
};


int main() {
  EXECS(Solution::isSameTree);
  return 0;
}
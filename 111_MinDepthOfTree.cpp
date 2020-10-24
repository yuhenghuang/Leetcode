#include "utils.hpp"
#include <queue>

using namespace std;

class Solution {
  public:
    int minDepth(TreeNode* root) {
      queue<TreeNode*> q;
      if (root) q.push(root);

      int res=0;
      while (!q.empty()) {
        ++res;
        int N = q.size();
        while (N--) {
          root = q.front();
          q.pop();
          if (!root->left && !root->right) return res;

          if (root->left) q.push(root->left);
          if (root->right) q.push(root->right);
        }
      }

      return res;
    }
};


int main() {
  Solution sol;
  TreeNode *root;

  readlines("Inputs/111_MinDepthOfTree.txt") {
    root = utils::parse_tree(line);

    cout << sol.minDepth(root) << endl;
  }

  return 0;
}
#include "DataStructure.h"

class Solution {
  private:
    int height, idx;
  public:
    int countNodes(TreeNode* root) {
      if (!root) return 0;
      height=0; idx=0;
      dfs(root, 0, 0);
      return (1 << (height-1)) + idx/2;
    }

    void dfs(TreeNode* node, int h, int i) {
      if (!node) {
        if (h>height) {
          height = h;
          idx = i;
        }
        else if (h==height && i>idx) {
          idx = i;
        }
        return;
      }

      dfs(node->right, h+1, i*2+1);
      dfs(node->left, h+1, i*2);
    }
};
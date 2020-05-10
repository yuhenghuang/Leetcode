#include "DataStructure.h"
#include <vector>
#include <iostream>
using namespace std;

static vector<int> vec = [](){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  return vector<int>();
}();

class Solution {
  private:
    int d_x, d_y, i_x, i_y;
  public:
    bool isCousins(TreeNode* root, int x, int y) {
      d_x=0; d_y=0; i_x=0; i_y=0;
      dfs(root, 0, 0, x, y);
      if (d_x==d_y && i_x/2 != i_y/2)
        return true;
      else
        return false;
    }
    void dfs(TreeNode* node, int idx, int depth, int& x, int& y) {
      if (!node) return;
      else if (node->val == x) {d_x = depth; i_x=idx; }
      else if (node->val == y) {d_y = depth; i_y=idx; }
      
      dfs(node->left, idx*2, depth+1, x, y);
      dfs(node->right, idx*2+1, depth+1, x, y);
    }
};
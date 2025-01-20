#include "DataStructure.h"
#include <vector>
using namespace std;

class Solution {
  public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
      return dfs(root, arr, 0);
    }
    bool dfs(TreeNode* node, vector<int>& arr, int idx) {
      if (!node || idx==arr.size()) return false;
      
      if (node->val == arr[idx]) {
        if (idx==arr.size()-1 && !node->left && !node->right)
          return true;
        else
          return dfs(node->left, arr, idx+1) || dfs(node->right, arr, idx+1);
      }
      else
        return false;
    }
};
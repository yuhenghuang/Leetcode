#include "DataStructure.h"
#include <vector>
using namespace std;

class FindElements {
  private:
    vector<bool> memo;
  public:
    FindElements(TreeNode* root) {
      memo = vector<bool>(1e6+1, false);
      dfs(root, 0);
    }

    void dfs(TreeNode* node, int idx) {
      if (!node || idx>1e6) return;
      else memo[idx] = true;
      dfs(node->left, idx*2+1);
      dfs(node->right, idx*2+2);
    }
    
    bool find(int target) {
      return memo[target];
    }
};
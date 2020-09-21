#include "utils.hpp"
#include <fstream>
#include <iostream>

using namespace std;

class Solution {
  private:
    int dfs(TreeNode* root, const bool& next = false, const bool& value = false) {
      if (!root) 
        return 0;
      else if (value) {
        return root->val;
      }
      else if (next) {
        return dfs(root->left, false, true) + dfs(root->right, false, true);
      }
      else {
        root->val = max(dfs(root->left) + dfs(root->right), root->val + dfs(root->left, true) + dfs(root->right, true));
        return root->val;
      }
    }
  public:
    int rob(TreeNode* root) {
      return dfs(root);
    }
};

int main() {
  Solution sol;

  fstream f("Inputs/337_HouseRobberIII.txt");
  string row;
  TreeNode* root;
  while (getline(f, row)) {
    root = utils::parse_tree(row);
    cout << sol.rob(root) << endl;
  }
  return 0;
}

#include "utils3.hpp"

class Solution {
  private:
    int res;
  public:
    int pathSum(TreeNode* root, int sum) {
      res=0;
      map<int, int> m;
      m.insert(make_pair(0, 1));
      dfs(root, m, 0, sum);
      return res;
    }
    void dfs(TreeNode* node, map<int, int> m, int curr, int& sum) {
      if (node==nullptr) return;
      curr += node->val;
      auto iter = m.find(curr-sum);
      if (iter!=m.end()) res+=iter->second;

      m[curr]++;
      // for (auto ptr=m.begin(); ptr!=m.end(); ++ptr)
      //   cout << ptr->first << " : " << ptr->second << ", ";
      // cout << endl;
      dfs(node->left, m, curr, sum);
      dfs(node->right, m, curr, sum);
    }
};

class PathSumIII {
  public:
    int pathSum(TreeNode* root, int sum) {
      if (root==nullptr) return 0;
      return dfs(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int dfs(TreeNode* root, int currSum, int sum) {
      if (root==nullptr) return 0;
      currSum+=root->val;
      return dfs(root->left, currSum, sum) + dfs(root->right, currSum, sum) + (currSum==sum?1:0);
    }
};

int main() {
  UFUNCS(Solution::pathSum);
  UFUNCS(PathSumIII::pathSum);
  return 0;
}
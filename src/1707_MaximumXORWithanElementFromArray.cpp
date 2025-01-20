#include <local_leetcode.hpp>

class Solution {
  private:
    void addNode(TreeNode* root, int num, int idx) {
      if (idx < 0)
        return;

      if ((num >> idx) & 1) {
        if (!root->left)
          root->left = new TreeNode();
        addNode(root->left, num, idx - 1);
      }
      else {
        if (!root->right)
          root->right = new TreeNode();
        addNode(root->right, num, idx - 1);
      }
    }

    int findMaxXor(TreeNode* root, int num, int idx) {
      if (!root->left && !root->right)
        return 0;
      else if (!root->left) 
        return (num & (1 << idx)) | findMaxXor(root->right, num, idx - 1);
      else if (!root->right)
        return ((num ^ (1 << idx)) & (1 << idx)) | findMaxXor(root->left, num, idx - 1);
      else {
        // choose left or right to optimize bit (i.e. = 1) at idx
        if ((num >> idx) & 1)
          return (1 << idx) | findMaxXor(root->right, num, idx - 1);
        else
          return (1 << idx) | findMaxXor(root->left, num, idx - 1);
      }
    }

  public:
    vector<int> maximizeXor(vector<int>& nums, const vector<vector<int>>& queries) {
      int n = nums.size();

      sort(nums.begin(), nums.end());

      vector<int> indicies(queries.size());
      iota(indicies.begin(), indicies.end(), 0);

      sort(
        indicies.begin(),
        indicies.end(),
        [&queries] (const int& i, const int& j) -> bool {
          return queries[i][1] < queries[j][1];
        }
      );


      TreeNode* root = new TreeNode();

      vector<int> res(queries.size());

      int j = 0;
      for (const int& i : indicies) {
        while (j < n && nums[j] <= queries[i][1]) 
          addNode(root, nums[j++], 30);

        res[i] = j == 0 ? -1 : findMaxXor(root, queries[i][0], 30);
      }

      ll::destroy(root);

      return res;
    }
};


int main() {
  EXECS(Solution::maximizeXor);
  return 0;
}
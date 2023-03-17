#include <local_leetcode.hpp>

class Solution {
  public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
      unordered_map<size_t, int> tree2id;
      int count[5001] = {0};
      vector<TreeNode*> res;

      function<size_t (TreeNode*)> dfs = [&tree2id, &count, &res, &dfs](TreeNode* root) -> size_t {
        if (!root) 
          return 0;

        // 9 bits for root->val + 200(0 ~ 400)
        // 13 bits for at most 5000 nodes
        // thus 32-bit int is not sufficient
        size_t tree = (dfs(root->left) << 22) | (dfs(root->right) << 9) | static_cast<size_t>(root->val + 200);

        int& id = tree2id[tree];
        
        if (id == 0)
          id = tree2id.size();

        if (++count[id] == 2)
          res.push_back(root);

        return id;
      }; 

      dfs(root);
      return res;
    }
};


int main() {
  EXECS(Solution::findDuplicateSubtrees);
  return 0;
}
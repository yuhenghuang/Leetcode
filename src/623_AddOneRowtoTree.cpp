#include <local_leetcode.hpp>

class Solution {
  private:
    vector<TreeNode*> nodes;


    void recurse(TreeNode* root, int v, int d) {
      if (!root)
        return;
      
      if (d==2) {
        root->left = nodes.emplace_back(new TreeNode(v, root->left, nullptr));
        root->right = nodes.emplace_back(new TreeNode(v, nullptr, root->right));
        return;
      }
      
      recurse(root->left, v, d-1);
      recurse(root->right, v, d-1);
    }
  
  public:
    ~Solution() {
      for (auto& node : nodes)
        delete node;
    }

    TreeNode* addOneRow(TreeNode* root, int v, int d) {
      if (d==1) 
        return nodes.emplace_back(new TreeNode(v, root, nullptr));
      
      recurse(root, v, d);
      return root;
    }
};


int main() {
  EXECS(Solution::addOneRow);
  return 0;
}

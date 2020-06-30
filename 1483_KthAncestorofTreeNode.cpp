#include "DataStructure.h"
#include <vector>
using namespace std;

class TreeAncestor {
  private:
    vector<vector<int>> memo;
  public:
    TreeAncestor(int n, vector<int>& parent) {
      vector<TreeNode*> forest(n);
      for (int i=0; i<n; ++i) 
        forest[i] = new TreeNode(i);

      TreeNode* root;
      for (int i=0; i<parent.size(); ++i) 
        if (parent[i]==-1)
          root = forest[i];
        else {
          if (!forest[parent[i]]->left)
            forest[parent[i]]->left = forest[i];
          else
            forest[parent[i]]->right = forest[i];
        }
        
      memo = vector<vector<int>>(n);
      dfs(root, vector<int>());
    }

    void dfs(TreeNode* node, vector<int> vec) {
      if (!node) return;
      memo[node->val] = vec;
      vec.push_back(node->val);
      dfs(node->left, vec);
      dfs(node->right, vec);
    }
    
    int getKthAncestor(int node, int k) {
      int s = memo[node].size();
      if (k>s) 
        return -1;
      else
        return memo[node][s-k];
    }
};

int main() {
  vector<int> vec = {-1,0,0,1,2,0,1,3,6,1};
  TreeAncestor obj(10, vec);
  obj.getKthAncestor(1,1);
  return 0;
}
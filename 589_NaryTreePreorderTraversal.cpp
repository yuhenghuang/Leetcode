#define NARY_NODE
#define NARY_TREE_NODE
#include "DataStructure.h"

using namespace std;

class Solution {
  private:
    void dfs(Node* root, vector<int>& res) {
      if (!root) return;
      
      res.push_back(root->val);
      for (Node* child : root->children)
        dfs(child, res);
    }
  
  public:
    vector<int> preorder(Node* root) {
      vector<int> res;
      dfs(root, res);
      
      return res;
    }
};

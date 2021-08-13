#define NARY_TREE_NODE
#include "utils3.hpp"

class Solution {
  public:
    vector<vector<int>> levelOrder(Node* root) {
      queue<Node*> q;
      vector<vector<int>> res;
      if (root != nullptr) 
        q.push(root);

      while (!q.empty()) {
        int N = q.size();
        vector<int> temp;
        while (N--) {
          root = q.front();
          q.pop();
          temp.push_back(root->val);
          for (auto child : root->children)
            q.push(child);
        }
        res.push_back(temp);
      }
      return res;
    }
};


int main() {
  UFUNCS(Solution::levelOrder);
  return 0;
}
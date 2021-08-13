#define NARY_TREE_NODE
#include "utils3.hpp"

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

    vector<int> preorderIter(Node* root) {
      typedef vector<Node*>::iterator iter_type;

      vector<int> res;

      stack<pair<Node*, iter_type>> s;

      while (!s.empty() || root) {
        while (root) {
          res.push_back(root->val);

          if (root->children.empty())
            root = nullptr;
          else {
            s.emplace(root, root->children.begin());
            root = root->children.front();
          }
        }

        if (!s.empty()) {
          if (++s.top().second == s.top().first->children.end())
            s.pop();
          else
            root = *s.top().second;
        }
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::preorder);
  UFUNCS(Solution::preorderIter);
  return 0;
}
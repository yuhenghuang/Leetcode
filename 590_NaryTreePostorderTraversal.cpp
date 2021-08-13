#define NARY_TREE_NODE
#include "utils3.hpp"

class Solution {
  private:
    void dfs(Node* root, vector<int>& res) {
      for (Node* child : root->children)
        dfs(child, res);

      res.push_back(root->val);
    }

  public:
    vector<int> postorder(Node* root) {
      if (!root) return {};

      vector<int> res;
      dfs(root, res);
      return res;
    }

    vector<int> postorderIter(Node* root) {
      vector<int> res;

      stack<pair<Node*, vector<Node*>::iterator>> s;
      while (!s.empty() || root) {
        while (root) {
          s.emplace(root, root->children.begin());

          root = root->children.empty() ? nullptr : root->children.front();
        }

        res.push_back(s.top().first->val);
        s.pop();

        if (!s.empty() && ++s.top().second != s.top().first->children.end())
          root = *(s.top().second);
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::postorder);
  UFUNCS(Solution::postorderIter);
  return 0;
}
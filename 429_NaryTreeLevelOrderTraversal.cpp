#define NARY_TREE_NODE
#include <local_leetcode.hpp>

class Solution {
  private:
    void dfs(Node* root, size_t level, vector<vector<int>>& res) {
      if (level == res.size())
        res.emplace_back();

      res[level++].push_back(root->val);

      for (auto& child : root->children)
        dfs(child, level, res);
    }

  public:
    vector<vector<int>> levelOrder(Node* root) {
      queue<Node*> q;
      vector<vector<int>> res;
      if (root != nullptr) 
        q.push(root);

      while (!q.empty()) {
        int N = q.size();
        vector<int>& temp = res.emplace_back();

        while (N--) {
          root = q.front();
          q.pop();

          temp.push_back(root->val);
          
          for (auto& child : root->children)
            q.push(child);
        }
        // res.push_back(temp);
      }
      return res;
    }

    vector<vector<int>> levelOrderDFS(Node* root) {
      vector<vector<int>> res;

      if (root)
        dfs(root, 0, res);

      return res;
    }
};


int main() {
  EXECS(Solution::levelOrder);
  EXECS(Solution::levelOrderDFS);
  return 0;
}

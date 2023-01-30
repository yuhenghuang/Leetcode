#include <local_leetcode.hpp>

class Solution {
  private:
    struct Node {
      char c;
      vector<Node*> children;
    };

    int res;

    int dfs(Node* root) {
      // first and second biggest path
      int fbig = 0, sbig = 0;

      for (auto& child : root->children) {
        // put dfs(child) outside of the following if statement
        int num = dfs(child);
        
        if (root->c != child->c) {
          if (num >= fbig) {
            sbig = fbig;
            fbig = num;
          }
          else if (num < fbig && num > sbig)
            sbig = num;
        }
      }

      res = max(res, fbig + sbig + 1);

      return fbig + 1;
    }

  public:
    int longestPath(vector<int>& parent, string s) {
      int n = parent.size();

      // question... why not use 2d array in a PO manner???
      Node* root = new Node[n];
      root->c = s[0];

      for (int i = 1; i < n; ++i) {
        Node* child = &root[i];
        
        root[parent[i]].children.push_back(child);
        child->c = s[i];
      }

      res = 0;
      dfs(root);

      delete[] root;

      return res;
    }

    int longestPathPO(vector<int>& parent, string s) {
      int n = parent.size();

      // count of children
      vector<int> children_count(n);

      for (int i = 1; i < n; ++i)
        ++children_count[parent[i]];

      queue<int> q;

      // push leaves
      for (int i = 0; i < n; ++i)
        if (children_count[i] == 0)
          q.push(i);

      // length of longest path starting at node i
      vector<int> dp(n, 1);

      int res = 1;

      // loop until root is at the front of queue
      while (q.front() > 0) {
        int c = q.front(); // child
        q.pop();

        int p = parent[c]; // parent

        if (s[c] != s[p]) {
          res = max(res, dp[c] + dp[p]);
          dp[p] = max(dp[p], dp[c] + 1);
        }

        if (--children_count[p] == 0)
          q.push(p);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::longestPath);
  EXECS(Solution::longestPathPO);
  return 0;
}
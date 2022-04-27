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
};


int main() {
  EXECS(Solution::longestPath);
  return 0;
}
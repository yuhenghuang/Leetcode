#include <local_leetcode.hpp>

class Solution {
  public:
    TreeNode* pruneTree(TreeNode* root) {
      if (!root)
        return nullptr;

      root->left = pruneTree(root->left);
      root->right = pruneTree(root->right);

      return (root->val == 1 || root->left || root->right) ? root : nullptr;
    }

    // iterative implementation of post order traversal
    TreeNode* pruneTreeIter(TreeNode* _root) {
      // whether the subtree has 1
      unordered_map<TreeNode*, bool> values;
      values[nullptr] = false;

      // whether a node is visited
      unordered_map<TreeNode*, bool> visited;

      stack<TreeNode*> s;

      TreeNode* root = _root;

      // post order traversal
      while (!s.empty() || root) {
        while (root) {
          s.push(root);
          root = root->left;
        }

        root = s.top();

        if (visited[root]) {
          values[root] = root->val || values[root->left] || values[root->right];
          
          s.pop();
          root = nullptr;
        }
        else {
          visited[root] = true;
          root = root->right;
        }
      }

      // reset root
      root = _root;

      if (!values[root])
        return nullptr;

      visited.clear();

      // post order once again
      while (!s.empty() || root) {
        while (root) {
          s.push(root);

          if (!values[root->left])
            root->left = nullptr;

          root = root->left;
        }

        root = s.top();

        if (visited[root]) {
          s.pop();
          root = nullptr;
        }
        else {
          if (!values[root->right])
            root->right = nullptr;

          visited[root] = true;
          root = root->right;
        }
      }
      
      return _root;
    }
};


int main() {
  EXECS(Solution::pruneTree);
  EXECS(Solution::pruneTreeIter);
  return 0;
}

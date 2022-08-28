#include <local_leetcode.hpp>

class Solution {
  private:
    TreeNode* res;

    int dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
      if (root==nullptr) 
        return 0;

      int count=0;
      if (root==p || root==q)
        count++;
      
      count+=dfs(root->left, p, q);
      count+=dfs(root->right, p, q);

      if (count>1 && res==nullptr)
        res = root;
      
      return count;
    }

    void recursion(TreeNode* root, stack<TreeNode*>& s, int v) {
      s.push(root);

      if (root->val > v)
        recursion(root->left, s, v);
      else if (root->val < v)
        recursion(root->right, s, v);
    }

  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      res = nullptr;
      dfs(root, p ,q);
      return res;
    }

    int lowestCommonAncestor(TreeNode* root, int p, int q) {
      return lowestCommonAncestor(
        root,
        ll::find_node(root, p, true),
        ll::find_node(root, q, true)
      )->val;
    }

    TreeNode* lowestCommonAncestorOn(TreeNode* root, TreeNode* p, TreeNode* q) {
      // O(h)

      stack<TreeNode*> sp, sq;

      recursion(root, sp, p->val);
      recursion(root, sq, q->val);

      if (sp.size() > sq.size())
        swap(sp, sq);

      while (sp.size() < sq.size())
        sq.pop();

      while (sp.top() != sq.top()) {
        sp.pop();
        sq.pop();
      }

      return sp.top();
    }

    int lowestCommonAncestorOn(TreeNode* root, int p, int q) {
      return lowestCommonAncestorOn(
        root,
        ll::find_node(root, p, true),
        ll::find_node(root, q, true)
      )->val;
    }
};


int main() {
  EXECS(Solution::lowestCommonAncestor, int, (TreeNode*, int, int));
  EXECS(Solution::lowestCommonAncestorOn, int, (TreeNode*, int, int));
  return 0;
}

#include "utils3.hpp"

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
        utils3::find_node_in_bst(root, p),
        utils3::find_node_in_bst(root, q)
      )->val;
    }

    TreeNode* lowestCommonAncestorOn(TreeNode* root, TreeNode* p, TreeNode* q) {
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
      return lowestCommonAncestor(
        root,
        utils3::find_node_in_tree(root, p, true),
        utils3::find_node_in_tree(root, q, true)
      )->val;
    }
};


int main() {
  UFUNCR(Solution::lowestCommonAncestor, int, TreeNode*, int, int);
  UFUNCR(Solution::lowestCommonAncestorOn, int, TreeNode*, int, int);
  return 0;
}
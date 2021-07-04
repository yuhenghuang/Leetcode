#include "utils2.hpp"

class Solution {
  private:
    void findDepthAndIndex(
      int d, int i, TreeNode* root, TreeNode* p, TreeNode* q, 
      pair<int, int>& pp, pair<int, int>& pq
    ) {
      
      // ...
      if (!root)
        return;
      else if (root == p) {
        pp.first = d;
        pp.second = i;
      }
      else if (root == q) {
        pq.first = d;
        pq.second = i;
      }

      findDepthAndIndex(d+1, i*2, root->left, p, q, pp, pq);
      findDepthAndIndex(d+1, i*2+1, root->right, p, q, pp, pq);
    }

    void findPath(
      TreeNode* root, TreeNode* p, TreeNode* q,
      stack<TreeNode*>& sp, stack<TreeNode*>& sq, stack<TreeNode*>& s
    ) {
      if (!root)
        return;

      s.push(root);

      if (root == p)
        sp = s;

      if (root == q)
        sq = s;

      findPath(root->left, p, q, sp, sq, s);
      findPath(root->right, p, q, sp, sq, s);

      s.pop();
    }

  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      stack<TreeNode*> sp, sq, s;

      findPath(root, p, q, sp, sq, s);

      while (sp.top() != sq.top()) {
        if (sp.size() > sq.size())
          sp.pop();
        else if (sp.size() < sq.size())
          sq.pop();
        else {
          sp.pop();
          sq.pop();
        }
      }

      return sp.top();
    }

    TreeNode* lowestCommonAncestorFailed(TreeNode* root, TreeNode* p, TreeNode* q) {
      // failed if depth is too large (depth >= 32)
      // need to adjust the index in each level when the parent node only has one child

      pair<int, int> pp, pq;
      findDepthAndIndex(0, 0, root, p, q, pp, pq);

      while (pp != pq) {
        if (pp.first > pq.first) {
          --pp.first;
          pp.second >>= 1;
        }
        else if (pp.first < pq.first) {
          --pq.first;
          pq.second >>= 1;
        }
        else {
          --pp.first;
          --pq.first;
          pp.second >>= 1;
          pq.second >>= 1;
        }
      }

      while (pp.first-- > 0) {
        int offset = 1 << pp.first;
        if (pp.second < offset) 
          root = root->left;
        else {
          root = root->right;
          pp.second -= offset;
        }
      }


      return root;
    }
};


int main() {

  TreeNode* root = utils2::universal_parser<TreeNode*>()("[3,5,1,6,2,0,8,null,null,7,4]");
  TreeNode* p = root->left; // 5
  TreeNode* q = root->left->right->right; // 4

  utils2::universal_print<TreeNode*>()(root);

  Solution sol;
  cout << sol.lowestCommonAncestor(root, p, q)->val << '\n';
  cout << sol.lowestCommonAncestorFailed(root, p, q)->val << endl;

  return 0;
}
#define _LL_DELETE_RETURN_POINTER
#include <local_leetcode.hpp>

class Solution {
  private:
    bool possible;

    int search(int i, int j, int t, vector<TreeNode*>& trees) {
      while (i <= j) {
        int m = i + (j - i) / 2;

        if (trees[m]->val < t)
          i = m + 1;
        else if (trees[m]->val > t)
          j = m - 1;
        else
          return m;
      }

      return -1;
    }


    void dfs(int i, int j, int k, int l, int r, vector<TreeNode*>& trees, vector<int>& s, vector<int>& res) {
      if (!possible) return;

      if (s.size() == trees.size() && res.empty()) {
        res = s;
        return;
      }

      if (i > j || k == -1)
        return;

      TreeNode* node = trees[k];

      if ((node->left && node->left->val <= l) || (node->right && node->right->val >= r)) {
        possible = false;
        return;
      }

      s.push_back(k);

      // maybe faster to use hash map in search?
      int lm = node->left ? search(i, k - 1, node->left->val, trees) : -1;
      dfs(i, k - 1, lm, l, node->val, trees, s, res);

      int mr = node->right ? search(k + 1, j, node->right->val, trees) : -1;
      dfs(k + 1, j, mr, node->val, r, trees, s, res);
    }

    // slow for corner cases, O(n2)
    TreeNode* deserialize(int l, int r, vector<int>& res, vector<TreeNode*>& trees) {
      if (l > r) return nullptr;
      
      TreeNode* node = trees[res[l]];

      TreeNode* root = new TreeNode(node->val);
      int k = l + 1;
      while (k <= r && res[k] < res[l])
        ++k;

      root->left = deserialize(l + 1, k - 1, res, trees);
      root->right = deserialize(k, r, res, trees);

      if (node->left && !root->left)
        root->left = new TreeNode(node->left->val);

      if (node->right && !root->right)
        root->right = new TreeNode(node->right->val);

      return root;
    }

    // fast!! O(n)
    TreeNode* deserialize(int*& i, int* j, int r, vector<TreeNode*>& trees) {
      if (i == j)
        return nullptr;

      TreeNode* node = trees[*i++];
      TreeNode* root = new TreeNode(node->val);
      
      if ((i != j ? trees[*i]->val : -1) < root->val)
        root->left = deserialize(i, j, root->val, trees);

      if ((i != j ? trees[*i]->val : -1) < r)
        root->right = deserialize(i, j, r, trees);

      // add leaves if needed
      if (node->left && !root->left)
        root->left = new TreeNode(node->left->val);

      if (node->right && !root->right)
        root->right = new TreeNode(node->right->val);

      return root;
    }

  public:
    TreeNode* canMerge(vector<TreeNode*>& trees) {
    // memory-safe approach
    // trees are not modified

      sort(
        trees.begin(), 
        trees.end(),
        [](TreeNode*& x, TreeNode*& y) {
          return x->val < y->val;
        }
      );
      
      int n = trees.size();

      // value to index
      unordered_map<int, int> m;
      for (int i = 0; i < n; ++i)
        m[trees[i]->val] = i;

      // find potential root candidates
      unordered_map<int, int>::iterator iter;
      vector<bool> root_candidate(n, true);
      for (int i = 0; i < n; ++i) {
        if (trees[i]->left) {
          iter = m.find(trees[i]->left->val);
          if (iter != m.end())
            root_candidate[iter->second] = false;
        }

        if (trees[i]->right) {
          iter = m.find(trees[i]->right->val);
          if (iter != m.end())
            root_candidate[iter->second] = false;
        }
      }

      // serialize BST
      vector<int> s, res;
      s.reserve(n);
      for (int i = 0; i < n; ++i)
        if (res.empty() && root_candidate[i]) {
          possible = true;
          s.clear();

          dfs(0, n - 1, i, 0, INT_MAX, trees, s, res);
        }

      int* i = res.data();
      // return res.empty() ? nullptr : deserialize(0, n - 1, res, trees);
      return res.empty() ? nullptr : deserialize(i, res.data() + n, INT_MAX, trees);
    }
};


int main() {
  EXECS(Solution::canMerge);
  return 0;
}

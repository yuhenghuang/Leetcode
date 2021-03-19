#include "utils2.hpp"


class SegmentTree {
  private:
    vector<int> tree;
    int n;

    int getMid(int s, int e) {
      return s + (e-s) / 2;
    }

    void updateUtil(int ss, int se, int ui, int ti) {
      if (ui<ss || ui>se) 
        return;

      ++tree[ti];
      if (ss<se) {
        int mid = getMid(ss, se);
        updateUtil(ss, mid, ui, ti*2+1);
        updateUtil(mid+1, se, ui, ti*2+2);
      }
    }

    int queryUtil(int ss, int se, int qs, int qe, int ti) {
      if (qs<=ss && qe>=se) 
        return tree[ti];
      else if (ss>qe || se<qs)
        return 0;

      int mid = getMid(ss, se);
      return queryUtil(ss, mid, qs, qe, ti*2+1) +
             queryUtil(mid+1, se, qs, qe, ti*2+2);
    }

  public:
    SegmentTree(int _n): n(_n) {
      int i=0;
      while ((1 << i) < _n )
        ++i;
      tree.resize((1<<(i+1)) - 1);
    }

    void update(int ui) {
      updateUtil(0, n-1, ui, 0);
    }

    int query(int qs, int qe) {
      return queryUtil(0, n-1, qs, qe, 0);
    }
};


struct BSTNode 
  : public TreeNode {
  // ...
  int small, count;
  BSTNode(int _v): small(0), count(1), TreeNode(_v) { }
};


class Solution {
  private:
    BSTNode* insert(TreeNode* root, int val) {
      if (!root)
        return new BSTNode(val);

      BSTNode* node = reinterpret_cast<BSTNode*>(root);
      if (val < node->val) {
        node->left = insert(node->left, val);
        ++node->small;
      }
      else if (val > node->val) {
        node->right = insert(node->right, val);
      }
      else
        ++node->count;

      return node;
    }

    int query(TreeNode* root, int val) {
      if (!root)
        return 0;

      BSTNode* node = reinterpret_cast<BSTNode*>(root);
      if (val < node->val)
        return query(node->left, val);
      else if (val > node->val)
        return node->count + node->small + query(node->right, val);
      else
        return node->small;
    }

    void update(int* tree, int n, int i) {
      while (i <= n) {
        ++tree[i];
        i += -i & i;
      }
    }

    int query(int* tree, int i) {
      int ans = 0;
      while (i > 0) {
        ans += tree[i];
        i -= -i & i;
      }
      return ans;
    }

  public:
    int createSortedArrayBST(vector<int>& instructions) {
      // super slow
      // all because the tree is not balanced

      static constexpr int mod = 1e9 + 7;
      int n = instructions.size();
      BSTNode* root = nullptr;
      int res=0;
      for (int i=1; i<n; ++i) {
        root = insert(root, instructions[i-1]);
        res += min(query(root, instructions[i]), i - query(root, instructions[i] + 1));
        res %= mod;
      }

      return res;
    }

    int createSortedArray(vector<int>& instructions) {
      // Binary Index Tree!!
      // to be studied...

      int m = 0;
      for (int num : instructions)
        if (num > m)
          m = num;

      int* tree = new int[++m];
      memset(tree, 0, m*sizeof(int));

      int n = instructions.size();
      static constexpr int mod = 1e9 + 7;
      int res=0;
      for (int i=0; i<n; ++i) {
        res += min(query(tree, instructions[i]-1), i - query(tree, instructions[i]));
        res %= mod;
        update(tree, m, instructions[i]);
      }

      delete[] tree;
      return res;
    }

    int createSortedArraySeg(vector<int>& instructions) {
      static constexpr int mod = 1e9 + 7;

      int n = 0;
      for (int num : instructions)
        if (num > n)
          n = num;

      SegmentTree tree(n);
      int res = 0;
      for (int num : instructions) {
        res += min(tree.query(0, num-2), tree.query(num, n-1));
        res %= mod;
        tree.update(num-1);
      }

      return res;
    }
};


int main() {
  {
    UFUNC(Solution::createSortedArray);
  }
  {
    UFUNC(Solution::createSortedArraySeg);
  }
  {
    UFUNC(Solution::createSortedArrayBST);
  }
  return 0;
}
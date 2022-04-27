#define _LL_PRINT_ARRAY_MAX_LENGTH 100
#include <local_leetcode.hpp>

class SegmentTree {
  private:
    int n;
    vector<int> stmax, stmin;
    const vector<int>& arr;

    int getMid(int ss, int se) {
      return ss + (se-ss)/2;
    }

    int constructUtil(int ss, int se, int si, 
                      vector<int> SegmentTree::* st, 
                      const int& (*comp)(const int&, const int &)) {
      // ...
      if (ss==se) {
        (this->*st)[si] = arr[ss];
        return arr[ss];
      }

      int mid = getMid(ss, se);
      (this->*st)[si] = comp(
        constructUtil(ss, mid, si*2+1, st, comp),
        constructUtil(mid+1, se, si*2+2, st, comp)
      );

      return (this->*st)[si];
    }


    int queryUtil(int ss, int se, int qs, int qe, int si) {
      if (ss>=qs && se<=qe) {
        if (stmax[si] < arr[qs-1])
          return se-ss+1;
        else if (stmin[si] >= arr[qs-1] || ss==se)
          return 0;
      }
      else if (se<qs || ss>qe)
        return 0;

      int mid = getMid(ss, se);
      return queryUtil(ss, mid, qs, qe, si*2+1) + queryUtil(mid+1, se, qs, qe, si*2+2);
    }

  public:
    SegmentTree(const vector<int>& _arr): arr(_arr) {
      n = arr.size();

      int i=0;
      while ((1 << i) < n)
        ++i;

      int maxsize = (1 << (i+1)) - 1;
      stmax.resize(maxsize);
      stmin.resize(maxsize);

      if (n>0) {
        constructUtil(0, n-1, 0, &SegmentTree::stmax, max);
        constructUtil(0, n-1, 0, &SegmentTree::stmin, min);
      }
    }

    int query(int qs) {
      return queryUtil(0, n-1, qs, n-1, 0);
    }
};


struct BSTNode 
  : public TreeNode {
  // ...
  int small, count;
  BSTNode(int _v): TreeNode(_v), small(0), count(1) { }
};


class ST {
  private:
    int n;
    vector<int> st;

    int getMid(int ss, int se) {
      return ss + (se-ss)/2;
    }

    void updateUtil(int ss, int se, int ui, int si) {
      if (ui<ss || ui>se)
        return;

      ++st[si];
      if (ss!=se) {
        int mid = getMid(ss, se);
        updateUtil(ss, mid, ui, si*2+1);
        updateUtil(mid+1, se, ui, si*2+2);
      }
    }

    int queryUtil(int ss, int se, int qs, int qe, int si) {
      if (ss>=qs && se<=qe)
        return st[si];
      else if (ss>qe || se<qs)
        return 0;

      int mid = getMid(ss, se);
      return queryUtil(ss, mid, qs, qe, si*2+1) +
             queryUtil(mid+1, se, qs, qe, si*2+2);
    }
  
  public:
    ST(int _n): n(_n) {
      int i=0;
      while ((1<<i) < n)
        ++i;

      st.resize((1 << (i+1)) - 1);
    }

    void update(int ui) {
      updateUtil(0, n-1, ui, 0);
    }

    int query(int qe) {
      return queryUtil(0, n-1, 0, qe, 0);
    }
};


class Solution {
  private:
    BSTNode* insert(TreeNode* root, int val) {
      if (!root)
        return new BSTNode(val);

      BSTNode* node = static_cast<BSTNode*>(root);
      if (val < node->val) {
        node->left = insert(node->left, val);
        ++node->small;
      }
      else if (val > root->val) {
        node->right = insert(node->right, val);
      }
      else
        ++node->count;

      return node;
    }

    int query(TreeNode* root, int val) {
      if (!root)
        return 0;

      BSTNode* node = static_cast<BSTNode*>(root);
      if (val < node->val)
        return query(node->left, val);
      else if (val > node->val)
        return node->count + node->small + query(node->right, val);
      else
        return node->small;
    }

    void update(vector<int>& bit, int i) {
      for (; i < bit.size(); i += i & (-i))
        ++bit[i];
    }

    int query(vector<int>& bit, int i) {
      int res = 0;

      for (; i > 0; i -= i & (-i))
        res += bit[i];

      return res;
    }

  public:
    vector<int> countSmaller(vector<int>& nums) {
      int n = nums.size();
      vector<int> res(n);
      BSTNode* root = nullptr;
      for (int i=n-2; i>=0; --i) {
        root = insert(root, nums[i+1]);
        res[i] = query(root, nums[i]);
      }

      ll::destroy<TreeNode>(root);

      return res;
    }

    vector<int> countSmallerBIT(vector<int>& nums) {
      auto p = minmax_element(nums.begin(), nums.end());

      int min_val = *p.first;
      int n = *p.second - min_val + 1;

      // binary index tree
      vector<int> bit(n + 1);

      vector<int> res(nums.size());

      for (int i = static_cast<int>(nums.size()) - 2; i >= 0; --i) {
        update(bit, nums[i+1] - min_val + 1);
        res[i] = query(bit, nums[i] - min_val);
      }

      return res;
    }

    vector<int> countSmallerST(vector<int>& nums) {
      int n = nums.size();
      vector<int> res(n);

      if (n<2) 
        return res;

      int num_min = nums[0];
      int num_max = nums[0];

      for (int i=1; i<n; ++i)
        if (nums[i]<num_min)
          num_min = nums[i];
        else if (nums[i]>num_max)
          num_max = nums[i];

      ST st(num_max-num_min+1);
      for (int i=n-2; i>=0; --i) {
        st.update(nums[i+1]-num_min);
        res[i] = st.query(nums[i]-num_min-1);
      }

      return res;
    }

    vector<int> countSmallerTLE(vector<int>& nums) {
      // TLE...
      // between O(nlogn) and O(n2)
      // try alternative implementation of segment tree
      // given -10e4 <= num <= 10e4
      int n = nums.size();
      vector<int> res;
      res.reserve(n);

      SegmentTree st(nums);
      for (int i=0; i<n; ++i)
        res.push_back(st.query(i+1));

      return res;
    }
};


int main() {
  EXECS(Solution::countSmaller);
  EXECS(Solution::countSmallerBIT);
  EXECS(Solution::countSmallerST);
  EXECS(Solution::countSmallerTLE);
  return 0;
}
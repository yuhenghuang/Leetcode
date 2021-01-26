#include "utils.hpp"


struct BSTNode 
  : public TreeNode {
  // ...
  long lsum;
  int small;
  BSTNode(long _l): lsum(_l), small(0), TreeNode(1) { }
};


class Solution {
  private:
    BSTNode* insert(TreeNode* root, long sum) {
      if (!root)
        return new BSTNode(sum);

      BSTNode* node = static_cast<BSTNode*>(root);
      if (sum < node->lsum) {
        node->left = insert(node->left, sum);
        ++node->small;
      }
      else if (sum > node->lsum) {
        node->right = insert(node->right, sum);
      }
      else
        ++node->val;

      return node;
    }

    int query(TreeNode* root, long sum) {
      if (!root)
        return 0;

      BSTNode* node = static_cast<BSTNode*>(root);
      if (sum < node->lsum)
        return query(node->left, sum);
      else if (sum > node->lsum)
        return node->val + node->small + query(node->right, sum);
      else
        return node->small;
    }

  public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
      map<long, int> treemap;
      treemap.emplace(0, 1);

      int res=0;
      long sum=0;
      for (int num : nums) {
        sum += num;

        auto st = treemap.lower_bound(sum-upper);
        auto ed = treemap.upper_bound(sum-lower);

        while (st!=ed)
          res += st++->second;

        ++treemap[sum];
      }

      return res;
    }

    int countRangeSumBST(vector<int>& nums, int lower, int upper) {
      BSTNode* root = new BSTNode(0);
      long sum = 0;

      int res = 0;
      for (int num : nums) {
        sum += num;
        res += query(root, sum-lower+1) - query(root, sum-upper);
        root = insert(root, sum);
      }

      return res;
    }

    int countRangeSumTLE(vector<int>& nums, int lower, int upper) {
      // TLE
      // inserting takes O(n)
      int n = nums.size();
      vector<long> sums;
      sums.reserve(n+1);
      sums.push_back(0);

      int res = 0;

      long sum = 0;
      for (int i=0; i<n; ++i) {
        sum += nums[i];

        res += upper_bound(sums.begin(), sums.end(), sum-lower) -
               lower_bound(sums.begin(), sums.end(), sum-upper);

        // costly to move existing elements
        sums.push_back(sum);
        sort(sums.begin(), sums.end());
      }

      return res;
    }
};


int main() {
  {
    UFUNC(Solution::countRangeSum);
  }
  {
    UFUNC(Solution::countRangeSumBST);
  }
  {
    UFUNC(Solution::countRangeSumTLE);
  }
  return 0;
}
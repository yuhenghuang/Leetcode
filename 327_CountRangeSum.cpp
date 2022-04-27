#include <local_leetcode.hpp>

struct BSTNode 
  : public TreeNode {
  // ...
  int small;
  long lsum;
  BSTNode(long _l): TreeNode(1), small(0), lsum(_l) { }
};


class Solution {
  private:
    BSTNode* insert(TreeNode* root, long sum) {
      if (!root)
        return new BSTNode(sum);

      BSTNode* node = reinterpret_cast<BSTNode*>(root);
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

      BSTNode* node = reinterpret_cast<BSTNode*>(root);
      if (sum < node->lsum)
        return query(node->left, sum);
      else if (sum > node->lsum)
        return node->val + node->small + query(node->right, sum);
      else
        return node->small;
    }

    vector<long long> uniquePrefixSumSorted(vector<int>& nums) {
      long long sum = 0;
      set<long long> prefix;

      // emtpy prefix sum
      prefix.insert(0);

      for (int i = 0; i < nums.size(); ++i)
        prefix.insert(sum += nums[i]);

      vector<long long> sorted(prefix.begin(), prefix.end());
      return sorted;
    }

    void update(vector<int>& bit, int i) {
      for (; i < bit.size(); i += i & (-i))
        ++bit[i];
    }

    int query(const vector<int>& bit, int i) {
      int res = 0;
      for (; i > 0; i -= i & (-i))
        res += bit[i];

      return res;
    }

  public:
    int countRangeSumBIT(vector<int>& nums, int lower, int upper) {
      // todo : optimize update by memorizing prefix sum -> index mapping

      vector<long long>&& sorted = uniquePrefixSumSorted(nums);

      int n = sorted.size();

      vector<int> bit(n + 1);

      int res = 0;

      long long sum = 0;

      // empty prefix sum
      update(
        bit,
        lower_bound(sorted.begin(), sorted.end(), 0) - sorted.begin() + 1
      );

      for (const int& num : nums) {
        sum += num;

        res += query(bit, upper_bound(sorted.begin(), sorted.end(), sum - lower) - sorted.begin()) \
          - query(bit, lower_bound(sorted.begin(), sorted.end(), sum - upper) - sorted.begin());

      update(
        bit,
        lower_bound(sorted.begin(), sorted.end(), sum) - sorted.begin() + 1
      );
      }

      return res;
    }

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

      ll::destroy<TreeNode>(root);

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
  EXECS(Solution::countRangeSum);
  EXECS(Solution::countRangeSumBST);
  EXECS(Solution::countRangeSumBIT);
  EXECS(Solution::countRangeSumTLE);
  return 0;
}
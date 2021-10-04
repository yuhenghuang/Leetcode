#include <numeric>
#include "utils3.hpp"

template <typename Tp>
class Array2DIterator {
  public:
    typedef typename vector<vector<Tp>>::iterator row_type;
    typedef typename vector<Tp>::iterator col_type;

  private:
    row_type row, end;
    col_type col;

  public:
    Array2DIterator(row_type _begin, row_type _end): row(_begin), end(_end), col(row->begin()) { }

    Array2DIterator& operator++() {
      ++col;

      while (!is_end() && col == row->end())
        col = (++row)->begin();
      
      return *this;
    }

    Tp operator*() const {
      return *col;
    }

    operator const row_type&() {
      return row;
    }

    bool is_end() const {
      return row == end;
    }
};


// parameters of rolling hash
static constexpr int MOD = 1e8 + 7;
static constexpr int MULTIPLIER = 12;
static constexpr int OFFSET = 1e7; // offset negative numbers

// longest possible input
// compute the power of multipliers once and for all
static const size_t N = 1e3;


class Solution {
  private:
    long multipliers[N];

    int hash(int i, int n, vector<int>& num) {
      int res = 0;
      for (; i < n; ++i) 
        res = (res * MULTIPLIER + num[i]) % MOD;

      return res;
    }

    bool compareArray(int i, vector<int>& arr, vector<int>& nums) {
      for (int j = 0; j < arr.size(); ++j)
        if (nums[i++] != arr[j])
          return false;

      return true;
    }


    int matchSubarray(int i, vector<int> arr, vector<int>& nums) {
      int m = arr.size();
      int n = nums.size();

      if (n - i < m)
          return -1;

      for (int i = 0; i < m; ++i)
        arr[i] += OFFSET;

      // initial hash values
      int target = hash(0, m, arr);
      int value = hash(i, i + m, nums);

      i += m;

      if (target == value && compareArray(i - m, arr, nums))
        return i;

      for (; i < n; ++i) {
        // update by rolling hash in O(1) time-complexity
        value *= MULTIPLIER;
        value -= static_cast<int>((nums[i - m] * multipliers[m]) % MOD);
        value = (value + nums[i] + MOD) % MOD;

        // only compare whole array when hash values are the same
        if (target == value && compareArray(i - m + 1, arr, nums))
          return i + 1;
      }

      return -1; 
    }

  public:
    Solution() {
      multipliers[0] = 1;
      for (size_t i = 1; i < N; ++i)
        multipliers[i] = (multipliers[i-1] * MULTIPLIER) % MOD;
    }

    bool canChooseWrongAnswer(vector<vector<int>>& groups, vector<int>& nums) {
      // the condition is loosened to non-consecutive arrays

      vector<int>::iterator iter1 = nums.begin();
      Array2DIterator<int> iter2(groups.begin(), groups.end());

      while (iter1 != nums.end() && !iter2.is_end()) 
        if (*iter1++ == *iter2) 
          ++iter2;

      return iter2.is_end();
    }

    bool canChoose(vector<vector<int>>& groups, vector<int>& _nums) {
      vector<int> nums(_nums);

      for (int i = 0; i < nums.size(); ++i)
        nums[i] += OFFSET;

      int i = 0;
      for (auto& arr : groups) {

        i = matchSubarray(i, arr, nums);

        if (i < 0)
          return false;
      }

      return true;
    }
};


int main() {
  UFUNCS(Solution::canChoose);
  return 0;
}
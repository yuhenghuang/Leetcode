#include <local_leetcode.hpp>


class Bit {
  private:
    static constexpr size_t N = numeric_limits<int>::digits - 1;

    array<int, 31> count;
    int num;

  public:
    Bit(): num(0) { count.fill(0); }

    Bit& operator+=(int num) {
      for (size_t i = 0; i < N; ++i)
        if (((num >> i) & 1) && ++count[i] == 1)
          this->num |= 1 << i;

      return *this;
    }

    Bit& operator-=(int num) {
      for (size_t i = 0; i < N; ++i)
        if (((num >> i) & 1) && --count[i] == 0)
          this->num ^= 1 << i;

      return *this;
    }

    bool operator!=(int num) const { return this->num != num; }

    const int& get_num() const { return num; }
};


class Solution {
  public:
    vector<int> smallestSubarrays(vector<int>& nums) {
      int n = nums.size();

      Bit remain, curr;

      for (int num : nums)
        remain += num;

      vector<int> res(n);
      int j = 0;
      for (int i = 0; i < n; ++i) {
        for (; j < n && curr != remain.get_num(); ++j)
          curr += nums[j];

        res[i] = max(j - i, 1);

        curr -= nums[i];
        remain -= nums[i];
      }

      return res;
    }
};


int main() {
  EXECS(Solution::smallestSubarrays);
  return 0;
}
#include <local_leetcode.hpp>

class Solution {
  private:
    pair<int, int> top2Freq(unordered_map<int, int>& m) {
      // largest, second largest frequency
      pair<int, int> out;

      int freq = 0;
      for (auto& p : m)
        if (p.second > freq)
          freq = p.second;

      out.first = freq;

      freq = 0;
      for (auto& p : m)
        if (p.second < out.first and p.second > freq)
          freq = p.second;

      out.second = freq;
      return out;
    }

    map<int, vector<int>> top2FreqNums(int start, vector<int>& nums) {
      // size
      int n = nums.size() / 2 + (nums.size() % 2 ? 1 - start : 0);

      // num, freq
      unordered_map<int, int> m;

      for (int i = start; i < nums.size(); i += 2)
        ++m[nums[i]];

      auto p = top2Freq(m);

      // n - freq, num
      map<int, vector<int>> out;

      for (auto& [num, f] : m) {
        if (f == p.first)
          out[n - p.first].push_back(num);
        else if (f == p.second)
          out[n - p.second].push_back(num);
      }

      // no second largest frequency
      if (p.second == 0)
        out[n];

      return out;
    }

  public:
    int minimumOperations(vector<int>& nums) {
      if (nums.size() < 3)
        return 0;

      map<int, vector<int>>&& freq0 = top2FreqNums(0, nums);
      map<int, vector<int>>&& freq1 = top2FreqNums(0, nums);

      auto i0 = freq0.begin();
      auto i1 = freq1.begin();

      if (i0->second.size() > 1 || i1->second.size() > 1 || i0->second.front() != i1->second.front())
        return i0->first + i1->first;
      else
        return min(i0->first + next(i1)->first, next(i0)->first + i1->first);
    }
};


int main() {
  EXECS(Solution::minimumOperations);
  return 0;
}
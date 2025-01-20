#include <local_leetcode.hpp>

class Solution {
  public:
    bool uniqueOccurrences(vector<int>& arr) {
      // number, frequency
      unordered_map<int, int> m;

      for (const int& num : arr)
        ++m[num];

      // frequencies
      unordered_set<int> s;

      for (auto& [_, f] : m)
        if (s.count(f))
          return false;
        else [[likely]]
          s.insert(f);

      return true;
    }
};


int main() {
  EXECS(Solution::uniqueOccurrences);
  return 0;
}
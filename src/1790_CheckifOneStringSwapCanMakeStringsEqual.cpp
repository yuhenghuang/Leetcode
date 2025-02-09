#include <local_leetcode.hpp>

class Solution {
  public:
    bool areAlmostEqual(string s1, string s2) {
      const int n = s1.size();

      vector<int> indices;
      for (int i = 0; i < n; ++i)
        if (s1[i] != s2[i]) 
          indices.push_back(i);

      if (indices.empty())
        return true;
      else if (indices.size() != 2)
        return false;

      int i = indices.front();
      int j = indices.back();
      
      return s1[i] == s2[j] and s1[j] == s2[i];
    }
};


int main() {
  EXECS(Solution::areAlmostEqual);
  return 0;
}
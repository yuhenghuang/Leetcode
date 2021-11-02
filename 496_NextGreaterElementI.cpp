#include "utils3.hpp"

class Solution {
  public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
      int m = nums1.size();
      int n = nums2.size();

      vector<int> res(m, -1);

      stack<int> s;
      unordered_map<int, int> dict;

      for (int i = n - 1; i >= 0; --i) {
        int num = nums2[i];
        while (!s.empty() && s.top() < num)
          s.pop();

        if (!s.empty() && s.top() > num)
          dict[num] = s.top();
        
        s.push(num);
      }

      for (int i = 0; i < m; ++i) {
        auto iter = dict.find(nums1[i]);
        if (iter != dict.end())
          res[i] = iter->second;
      }

      return res;
    }
};


int main() {
  UFUNCS(Solution::nextGreaterElement);
  return 0;
}
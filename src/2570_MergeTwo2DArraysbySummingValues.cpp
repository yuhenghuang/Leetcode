#include <local_leetcode.hpp>

class Solution {
  public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
      vector<vector<int>> res;

      auto iter1 = nums1.begin();
      auto iter2 = nums2.begin();
      while (iter1 != nums1.end() and iter2 != nums2.end()) {
        if (iter1->front() < iter2->front())
          res.push_back(std::move(*iter1++));
        else if (iter1->front() > iter2->front()) 
          res.push_back(std::move(*iter2++));
        else {
          // vector<int>& vec = res.emplace_back(2);
          // // push id
          // vec[0] = iter1->front();
          // vec[1] = iter1++->back() + iter2++->back();
          res.emplace_back(std::move(*iter1++)).back() += iter2++->back();
        }
      } 

      while (iter1 != nums1.end())
        res.push_back(std::move(*iter1++));

      while (iter2 != nums2.end())
        res.push_back(std::move(*iter2++));
      
      return res;
    }
};


int main() {
  EXECS(Solution::mergeArrays);
  return 0;
}
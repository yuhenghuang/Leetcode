#include "utils3.hpp"

class Solution {
  private:
    unordered_map<int, vector<int>> m;

  public:
    Solution(vector<int>& nums) {
      for (int i = 0; i < nums.size(); ++i)
        m[nums[i]].push_back(i);
    }
    
    int pick(int target) {
      vector<int>& vec = m[target];
      return vec[rand() % vec.size()];
    }
};


int main() {
  UFUNCX(
    CTOR(vector<int>&),
    &Solution::pick
  );
  return 0;
}
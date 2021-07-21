#include "utils3.hpp"

class Solution {
  private:
    const vector<int>& nums;

  public:
    Solution(vector<int>& _nums): nums(_nums){ }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
      return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
      vector<int> res;
      res = nums;

      for (int i = res.size() - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(res[i], res[j]);
      }

      return res;
    }
};


int main() {
  UFUNCX(
    BIND(vector<int>&),
    &Solution::reset,
    &Solution::shuffle
  );
  return 0;
}
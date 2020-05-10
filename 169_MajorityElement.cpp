#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    int majorityElement(vector<int>& nums) {
      unordered_map<int, int> dict;
      int N = nums.size();
      for (int i=0; i<N; ++i) {
        auto iter=dict.find(nums[i]);
        if (iter!=dict.end()) {
          ++iter->second;
          if (iter->second>N/2) return nums[i];
        }
        else {
          dict.insert(make_pair(nums[i], 1));
        }
      }
      return nums[0];
    }
};

int main() {
  Solution sol;
  vector<int> vec {6,5,5};
  cout << sol.majorityElement(vec) << endl;
  return 0;
}
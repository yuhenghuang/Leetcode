#include <vector>
#include <map>
using namespace std;

class Solution {
  private:
    vector<vector<int>> res;
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      map<int, int> m;
      for (int& num : nums) 
        ++m[num];

      vector<int> tri;
      dfs(0, tri, m, m.begin());
      return res;
    }

    void dfs(int target, vector<int>& triplet, map<int, int>& m, map<int, int>::iterator iter) {
        if (triplet.size()==2) {
          if (target>=triplet.back()) {
            iter = m.find(target);
            if (iter!=m.end() && !iter->second) {
              triplet.push_back(iter->first);
              res.push_back(triplet);
              triplet.pop_back();
            }
          }
          return;
        }

      for(; iter!=m.end(); ++iter) {
        if (!iter->second) continue;
        triplet.push_back(iter->first);
        --iter->second;
        dfs(target-iter->first, triplet, m, iter);
        triplet.pop_back();
        ++iter->second;
      }
    }
};

int main() {
  Solution sol;
  vector<int> nums = {-1, 0, 1, 2, -1, 4};
  sol.threeSum(nums);
  return 0;
}
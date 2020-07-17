#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <iterator>
using namespace std;

class Compare {
  private:
    unordered_map<int, int>& m;
  public:
    Compare(unordered_map<int, int>& map): m(map) {}
    bool operator()(const int& l, const int& r) const {
      return m[l] > m[r];
    }
};

class Solution {
  public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int, int> m;
      for (int& num : nums)
        ++m[num];

      vector<int> unique;
      for (auto iter=m.begin(); iter!=m.end(); ++iter)
        unique.push_back(iter->first);

      sort(unique.begin(), unique.end(), Compare(m));

      unique.resize(k);
      return unique;
    }
};

int main() {
  Solution sol;
  vector<int> nums = {4,1,-1,2,-1,2,3};
  vector<int> res = sol.topKFrequent(nums, 2);
  copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
  return 0;
}
#include <vector>
#include <iostream>
#include <iterator>
#include <stdlib.h>

using namespace std;

class Solution {
  private:
    int n;
    vector<int> acc;
    vector<vector<int>> rects;
    int binary_search(int num) {
      int l=0, r=n, m;
      while (l<r) {
        m = l + (r-l)/2 + (r-l)%2;
        if (acc[m]>num)
          r = m-1;
        else
          l = m;
      }
      return l;
    }
  public:
    Solution(vector<vector<int>>& rects) {
      n = rects.size();
      this->rects = rects;
      acc.push_back(0);
      for (auto &rect : rects) 
        acc.push_back(acc.back() + (rect[2]-rect[0]+1) * (rect[3]-rect[1]+1));
    }
    
    vector<int> pick() {
      int num = rand() % acc.back();
      int idx = binary_search(num);
      num -= acc[idx];
      auto &rect = rects[idx];

      int l = rect[2] - rect[0] + 1;
      return {rect[0] + num % l, rect[1] + num / l};
    }
};

int main() {
  vector<vector<int>> rects = {{-2,-2,-1,-1}, {1,0,3,0}};
  Solution sol(rects);
  vector<int> res;
  for (int i=0; i<3; ++i) {
    res = sol.pick();
    copy(res.begin(), res.end(), ostream_iterator<int>(cout, ", "));
  }
  return 0;
}
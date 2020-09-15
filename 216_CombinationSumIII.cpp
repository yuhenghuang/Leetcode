#include <vector>
#include <iostream>
#include <iterator>

using namespace std;

class Solution {
  private:
    vector<vector<int>> res;
    vector<int> stack;

    void dfs(int s, int k, int n) {
      if (k==0) {
        if (n==0)
          res.push_back(stack);
        return;
      }

      for (int i=s+1; i<10; ++i) {
        stack.push_back(i);
        dfs(i, k-1, n-i);
        stack.pop_back();
      }
    }
  public:
    vector<vector<int>> combinationSum3(int k, int n) {
      dfs(0, k, n);
      return res;
    }
};

int main() {
  Solution sol;
  vector<vector<int>> res = sol.combinationSum3(3, 9);
  for (auto &comb : res) {
    copy(comb.begin(), comb.end(), ostream_iterator<int>(cout, ", "));
    cout << endl;
  }

  return 0;
}
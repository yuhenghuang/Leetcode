#include "utils.hpp"
#include <algorithm>

using namespace std;

class Solution {
  public:
    typedef vector<int>::iterator iter_type;

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
      vector<int> res;
      res.reserve(k);

      int l=0, r=20001, m, diff;
      iter_type low, high;
      while (l<r) {
        m = l + (r-l)/2;
        low = lower_bound(arr.begin(), arr.end(), x-m);
        high = upper_bound(arr.begin(), arr.end(), x+m);

        diff = high - low;

        if (diff < k)
          l = m+1;
        else
          r = m;
      }

      low = lower_bound(arr.begin(), arr.end(), x-l+1);
      high = upper_bound(arr.begin(), arr.end(), x+l-1);
      iter_type lower = lower_bound(arr.begin(), arr.end(), x-l);

      iter_type iter = low - min(max(k - (high - low), 0L), low - lower);
      while (k>0) {
        res.push_back(*iter);
        ++iter;
        --k;
      }

      return res;
    }
};

int main() {
  Solution sol;

  vector<int> arr, res;
  utils::parse_vector_1d<int> parser;
  string line;
  int k, x;
  while (getline(cin, line)) {
    arr = parser(line);
    cin >> k >> x;

    res = sol.findClosestElements(arr, k, x);
    utils::print_vector_1d(res);
    cin.get();
  }

  return 0;
}

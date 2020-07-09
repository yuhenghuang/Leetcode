#include <queue>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution {
  public:
    int nthUglyNumber(int n) {
      unordered_set<long> s;
      priority_queue<long, vector<long>, greater<long>> heap;
      long factors[3] = {2, 3, 5};
      long res = 1;
      long temp;
      while (--n) {
        for (long& i : factors) {
          temp = res * i;
          if (temp >0 && s.find(temp)==s.end()) {
            s.insert(temp);
            heap.push(temp);
          }
        }
        res = heap.top(); heap.pop();
      }
      return res;
    }
};

int main() {
  Solution sol;
  cout << sol.nthUglyNumber(1690) << endl;
  return 0;
}
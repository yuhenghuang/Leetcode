#include <vector>
#include <iostream>
#include <iterator>
using namespace std;

class Solution {
  public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
      if (cells[0] || cells[7]) {
        vector<int> temp(8, 0);
        for (int i=1; i<7; ++i)
          temp[i] = cells[i-1] == cells[i+1];
        --N;
        cells = temp;
      }

      int st = 0, mask = 0;
      for (int i=0; i<6; ++i) {
        st += (cells[i+1] << i);
        mask += 1 << i;
      }

      int ed = st, loop = 0;
      do {
        st = (~((st << 1) ^ (st >> 1)) & mask);
        ++loop;
      } while(st!=ed);

      N = N % loop;
      while (N--) 
        st = (~((st << 1) ^ (st >> 1)) & mask);

      for (int i=0; i<6; ++i)
        cells[i+1] = 1 & (st >> i);
      return cells;
    }
};

int main() {
  Solution sol;
  vector<int> cells = {1,0,0,1,0,0,1,0};
  vector<int> res = sol.prisonAfterNDays(cells, 1000000000);
  copy(res.begin(), res.end(), ostream_iterator<int>(cout, " "));
  return 0;
}
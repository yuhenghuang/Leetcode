#include <local_leetcode.hpp>

class Solution {
  private:
    int garbage_2_int(char g) const {
      switch (g) {
        case 'M': return 0;
        case 'P': return 1;
        case 'G': return 2;
        default: return -1;
      }
    }

  public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
      const int n = garbage.size();

      int count = 0; // total amount of garbage
      int distance[3] = {0};

      int d = 0;
      for (int i = 0; i < n; ++i) {
        for (char c : garbage[i]) {
          int j = garbage_2_int(c);

          ++count;

          // update distance for grabage type j
          if (distance[j] < d)
            distance[j] = d;
        }

        if (i + 1 < n) [[ unlikely ]]
          d += travel[i];
      }

      return count + reduce(begin(distance), end(distance));
    }
};


int main() {
  EXECS(Solution::garbageCollection);
  return 0;
}
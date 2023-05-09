#include <local_leetcode.hpp>

class Solution {
  private:
    int binary_search(const vector<int>& arr, int r, int t) {
      int l = 0;

      while (l < r) {
        int m = l + (r - l) / 2;

        if (arr[m] <= t)
          l = m + 1;
        else
          r = m;
      }

      return l;
    }

  public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
      const int n = obstacles.size();

      vector<int> res(n);

      int k = 0;
      for (int i = 0; i < n; ++i) {
        int num = obstacles[i];
        
        int j = binary_search(obstacles, k, num);

        if (j < k)
          obstacles[j] = num;
        else
          obstacles[k++] = num;

        res[i] = j + 1;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::longestObstacleCourseAtEachPosition);
  return 0;
}
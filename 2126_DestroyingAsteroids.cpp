#include <local_leetcode.hpp>

class Solution {
  public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
      sort(asteroids.begin(), asteroids.end());

      long m = mass;
      for (int i = 0; i < asteroids.size(); ++i) {
        if (m < asteroids[i])
          return false;

        m += asteroids[i];
      }

      return true;
    }
};


int main() {
  EXECS(Solution::asteroidsDestroyed);
  return 0;
}
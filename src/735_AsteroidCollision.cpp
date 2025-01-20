#include "utils.hpp"

using namespace std;

class Solution {
  public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
      vector<int> res;
      res.reserve(asteroids.size());

      int offset;
      for (int w : asteroids) {
        while (!res.empty() && res.back()>0 && w<0) {
          offset = res.back() + w;
          if (offset<=0)
            res.pop_back();

          if (offset>=0)
            w = 0;
        }

        if (w!=0)
          res.push_back(w);
      }

      return res;
    }
};


int main() {
  Solution sol;

  vector<int> asteroids, res;
  utils::parse_vector_1d<int> parser;

  readlines("Inputs/735_AsteroidCollision.txt") {
    asteroids = parser(line);

    res = sol.asteroidCollision(asteroids);
    utils::print_vector_1d(res);
  }

  return 0;
}
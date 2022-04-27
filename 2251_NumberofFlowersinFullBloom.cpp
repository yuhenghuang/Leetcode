#include <local_leetcode.hpp>

class Solution {
  public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
      // time, change in blooming flowers
      map<int, int> treemap;
      for (auto& f : flowers) {
        ++treemap[f[0]];
        --treemap[f[1] + 1];
      }

      // because we cannot sort persons itself.
      // instead, sort the index of persons
      vector<int> index(persons.size());
      iota(index.begin(), index.end(), 0);

      sort(
        index.begin(), index.end(),
        [&persons] (const int& i, const int& j) -> bool {
          return persons[i] < persons[j];
        }
      );

      vector<int> res(persons.size());

      // count of blooming flowers
      int bloom = 0;

      // iterator over sorted index of persons
      auto i = index.begin();

      // time, change in blooming flowers
      for (auto& [t, v] : treemap) {
        for (; i != index.end() && persons[*i] < t; ++i)
          res[*i] = bloom;

        bloom += v;
      }

      // not necessary
      // for (; i != index.end(); ++i)
      //   res[*i] = bloom;

      return res;
    }
};


int main() {
  EXECS(Solution::fullBloomFlowers);
  return 0;
}
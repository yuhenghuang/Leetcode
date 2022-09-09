#include <local_leetcode.hpp>

class Solution {
  public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
      map<int, vector<int>, greater<int>> m;

      for (auto& p : properties)
        m[p[0]].push_back(p[1]);

      int res = 0;

      auto iter = m.begin();

      int def = *max_element(iter->second.begin(), iter->second.end());

      for (++iter; iter != m.end(); ++iter) {
        int temp = def;
        for (const int& d : iter->second) {
          if (d < def)
            ++res;
          else if (d > temp)
            temp = d;
        }

        // update current max defense
        def = temp;
      }

      return res;
    }

    int numberOfWeakCharactersNew(vector<vector<int>>& properties) {
      typedef pair<int, int> ii_t;
      vector<ii_t> props(properties.size());

      transform(
        properties.begin(), properties.end(), props.begin(), 
        [](const vector<int>& p) -> ii_t {
          return {p.front(), p.back()};
        }
      );

      // attack high -> low
      sort(
        props.begin(), props.end(),
        [](const ii_t& p, const ii_t& q) {
          return p.first > q.first;
        }
      );

      int atk = props.front().first;
      int def = INT_MIN;

      int def_prev = INT_MIN;

      int res = 0;
      for (auto& [a, d] : props) {
        // lower level of attacks
        // update def
        if (a < atk)
          def = def_prev;

        if (d < def)
          ++res;
        else if (d > def_prev)
          def_prev = d;

        atk = a;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::numberOfWeakCharacters);
  EXECS(Solution::numberOfWeakCharactersNew);
  return 0;
}

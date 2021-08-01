#include "utils3.hpp"

class Solution {
  private:
    int g2i(const string& gene, unordered_map<char, int>& mapping) {
      int i = 0;
      for (char c : gene) {
        i <<= 2;
        i ^= mapping[c];
      }

      return i;
    }

  public:
    int minMutation(string start, string end, vector<string>& bank) {
      if (start == end) return 0;

      // encode each gene by 2 bits
      unordered_map<char, int> mapping {
        {'A', 0},
        {'C', 1},
        {'G', 2},
        {'T', 3}
      };

      int ones = (1 << 16) - 1;
      vector<int> masks;
      for (int i = 0; i < 16; i +=2)
        masks.push_back(ones ^ (3 << i));

      int s = g2i(start, mapping);
      int e = g2i(end, mapping);

      unordered_map<int, bool> seen;
      for (string& g : bank) {
        int i = g2i(g, mapping);
        seen[i] = false;
      }

      if (seen.count(e) == 0)
        return -1;

      queue<int> q;
      q.push(s);

      int res = 1;
      while (!q.empty()) {
        int n = q.size();
        while (n--) {
          int v = q.front();
          q.pop();
          // loop over genes
          for (int i = 0; i < 16; i += 2) {
            int b = (v >> i) & 3;
            for (int j = 0; j < 4; ++j)
              if (j != b) {
                int w = (v & masks[i >> 1]) ^ (j << i);

                auto iter = seen.find(w);
                if (iter != seen.end() && !iter->second) {
                  if (iter->first == e)
                    return res;

                  q.push(iter->first);              
                  iter->second = true;
                }
              }
          }
        } // end of loop over each level

        ++res;
      }


      return -1;
    }
};


int main() {
  UFUNCS(Solution::minMutation);
  return 0;
}
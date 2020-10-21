#include "utils.hpp"
#include <unordered_map>
#include <bitset>

using namespace std;

class Solution {
  public:
    vector<string> findRepeatedDnaSequences(string s) {
      int dict[26] = {0};
      dict[0] = 0;
      dict['C'-'A'] = 1;
      dict['G'-'A'] = 2;
      dict['T'-'A'] = 3;

      int n = s.size();
      vector<string> res;

      constexpr int mask = (1 << 20) - 1;
      bitset<mask+1> b1, b2; 
      int curr = 0;
      for (int i=0; i<n; ++i) {
        curr <<= 2;
        curr |= dict[s[i]-'A'];
        if (i>=9) {
          curr &= mask;

          if (b1[curr] && !b2[curr]) {
            res.push_back(s.substr(i-9, 10));
            b2.set(curr);
          }
          else {
            b1.set(curr);
          }
        }
      }

      return res;
    }

    vector<string> findRepeatedDnaSequencesHashmap(string s) {
      int dict[26] = {0};
      dict[0] = 0;
      dict['C'-'A'] = 1;
      dict['G'-'A'] = 2;
      dict['T'-'A'] = 3;

      int n = s.size();

      unordered_map<int, int> count;
      vector<string> res;

      constexpr int mask = (1 << 20) - 1;
      int curr = 0;
      for (int i=0; i<n; ++i) {
        curr <<= 2;
        curr |= dict[s[i]-'A'];
        if (i>=9) {
          curr &= mask;
          if (count[curr]==1)
            res.push_back(s.substr(i-9, 10));

          ++count[curr];
        }
      }

      return res;
    }
};


int main() {
  Solution sol;

  vector<string> res;

  readlines("Inputs/187_RepeatedDNASequences.txt") {
    res = sol.findRepeatedDnaSequences(line);

    utils::print_vector_1d(res);
  }

  return 0;
}
#include "utils.hpp"
#include <algorithm>

class Solution {
  public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
      int n = tokens.size();
      int res = 0, score = 0;

      sort(tokens.begin(), tokens.end());
      int i = 0, j = n-1;
      while (i<=j) {
        if (P>=tokens[i]) {
          P -= tokens[i++];
          ++score;
        }
        else if (score>0) {
          P += tokens[j--];
          --score;
        }
        else
          break;

        res = max(res, score);
      }

      return res;
    }
};


int main() {
  Solution sol;
  vector<int> tokens;
  int P;
  vector<string> args;

  utils::parse_vector_1d<int> parser;

  readlines("Inputs/948_BagOfTokens.txt") {
    args = utils::string_split(line);
    tokens = parser(args[0]);
    P = stoi(args[1]);

    cout << sol.bagOfTokensScore(tokens, P) << endl;
  }

  return 0;
}
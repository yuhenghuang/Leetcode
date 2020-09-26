#include "utils.hpp"
#include <fstream>

using namespace std;

class Solution {
  public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
      int n = timeSeries.size();

      int res=0;
      int st=-1, ed=-1;
      for (int& time : timeSeries) {
        if (time>ed) {
          res += ed-st;
          st = time;
          ed = time + duration;
        }
        else {
          ed = time + duration;
        }
      }
      res += ed-st;

      return res;
    }
};

int main() {
  Solution sol;

  vector<string> args;
  vector<int> ts;
  int duration;
  utils::parse_vector_1d<int> parser;

  ifstream f("Inputs/495_TeemoAttacking.txt");
  string line;
  while (getline(f, line)) {
    args = utils::string_split(line);
    ts = parser(args[0]);
    duration = stoi(args[1]);
    cout << sol.findPoisonedDuration(ts, duration) << endl;
  }

  return 0;
}

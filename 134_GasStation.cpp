#include "utils.hpp"
#include <fstream>

using namespace std;

class Solution {
  public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int n = gas.size(), sum = 0;

      for (int i=0; i<n; ++i) {
        sum += gas[i];
        sum -= cost[i];
      }
      if (sum<0 || n==0) return -1;

      int res;

      sum=-1;
      for (int i=0; i<n; ++i) {
        if (sum<0) {
          sum = 0;
          res = i;
        }
        sum += gas[i];
        sum -= cost[i];
      }

      return res;
    }
};


int main() {
  Solution sol;
  utils::parse_vector_1d<int> parser;
  vector<int> gas, cost;
  vector<string> args;

  fstream f("Inputs/134_GasStation.txt");
  string line;
  while (getline(f, line)) {
    args.clear();
    args = utils::string_split(line);
    gas = parser(args[0]);
    cost = parser(args[1]);

    cout << sol.canCompleteCircuit(gas, cost) << endl;
  }

  return 0;
}
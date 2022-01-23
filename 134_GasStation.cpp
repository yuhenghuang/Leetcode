/*
#include "utils.hpp"
#include <fstream>

using namespace std;
*/

#include <local_leetcode.hpp>


class Solution {
  public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int n = gas.size(), sum = 0;

      for (int i = 0; i < n; ++i) 
        sum += gas[i] - cost[i];

      if (sum < 0 || n  == 0) 
        return -1;

      int res;

      sum = -1;
      for (int i = 0; i < n; ++i) {
        if (sum < 0) {
          sum = 0;
          res = i;
        }
        sum += gas[i] - cost[i];
      }

      return res;
    }

    int canCompleteCircuitOn(vector<int>& gas, vector<int>& cost) {
      int n = gas.size();

      int remain[n];
      
      int curr = 0;
      for (int i = 0; i < n; ++i)
        remain[i] = curr += gas[i] - cost[i];

      if (n == 0 || remain[n-1] < 0)
        return -1;

      int res = 0;
      int min_val = INT_MAX;
      for (int i = 0; i < n; ++i) 
        if (remain[i] < min_val) {
          min_val = remain[i];
          res = i + 1;
        }

      return res % n;
    }
};


int main() {
  /*
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
  */

  EXECS(Solution::canCompleteCircuit);
  EXECS(Solution::canCompleteCircuitOn);
  return 0;
}
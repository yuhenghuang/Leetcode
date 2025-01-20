#include "utils.hpp"
#include <queue>

using namespace std;

class RecentCounter {
  private:
    int records;
    queue<int> q;
  public:
    RecentCounter() {
      records = 0;
    }
  
    int ping(int t) {
      q.push(t);
      ++records;
      while (q.front() < t-3000) {
        q.pop();
        --records;
      }

      return records;
    }
};


int main() {
  RecentCounter obj;
  
  vector<string> args;
  vector<string> ops;
  vector<vector<int>> pings;
  vector<int> res;

  utils::parse_vector_1d<string> parser_str;
  utils::parse_vector_2d<int> parser_int;

  ifstream f("Inputs/933_NumberofRecentCalls.txt");
  string line;
  while (getline(f, line)) {
    args = utils::string_split(line);
    ops = parser_str(args[0]);
    pings = parser_int(args[1]);

    res.clear();
    int n = ops.size();
    res.reserve(n);
    res.push_back(-1);

    for (int i=1; i<n; ++i) {
      res.push_back(obj.ping(pings[i][0]));
    }

    utils::print_vector_1d(res);
  }

  return 0;
}
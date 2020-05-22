#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;


class Comp {
  private:
    unordered_map<char, int>& __m;
  public:
    Comp(unordered_map<char, int>& f): __m(f) { }
    bool operator() (const char& x, const char& y) const {
      return __m[x] > __m[y];
  }
};

class Solution {
  public:
    string frequencySort(string s) {
      unordered_map<char, int> freq;
      for (char c : s) {
        ++freq[c];
      }

      vector<char> vec(freq.size());
      int idx=-1;
      for (auto iter=freq.begin(); iter!=freq.end(); ++iter) {
        vec[++idx] = iter->first;
      }

      sort(vec.begin(), vec.end(), Comp(freq));

      stringstream ss;
      for (char c : vec) {
        ss << string(freq[c], c);
      }
      return ss.str();
    }
};


int main() {
  Solution sol;
  cout << sol.frequencySort("Aabb") << endl;
  return 0;
}

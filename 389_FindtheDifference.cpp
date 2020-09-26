#include "utils.hpp"
#include <fstream>

using namespace std;

class Solution {
  public:
    char findTheDifference(string s, string t) {
      int count_s[26] = {0}, count_t[26] = {0};
      for (char& c: s)
        ++count_s[c-'a'];

      for (char& c: t)
        ++count_t[c-'a'];

      for (int i=0; i<26; ++i)
        if (count_s[i]!=count_t[i])
          return char('a'+i);

      return '0';
    }
};

int main() {
  Solution sol;

  ifstream f("Inputs/389_FindtheDifference.txt");
  vector<string> args;
  utils::parse_vector_1d<string> parser;
  string line;
  while (getline(f, line)) {
    args = parser(line);
    cout << sol.findTheDifference(args[0], args[1]) << endl;
  }

  return 0;
}

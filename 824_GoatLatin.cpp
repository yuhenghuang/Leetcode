#include <string>
#include <iostream>
#include <sstream>
#include <unordered_set>

using namespace std;

class Solution {
  public:
    string toGoatLatin(string S) {
      unordered_set<char> vowels = {'a','i','u','e','o','A','I','U','E','O'};
      int count = 1;
      S.push_back(' ');
      size_t n = S.size(), idx=0, delimiter;
      string word;
      stringstream ss;
      while (idx<n) {
        delimiter = S.find(' ', idx);
        word = S.substr(idx, delimiter-idx);
        if (vowels.find(word[0])==vowels.end()) {
          word.push_back(word[0]);
          word.erase(0, 1);
        }
        word += "ma";
        for (int i=0; i<count; ++i)
          word.push_back('a');
        word.push_back(' ');

        ss << word;
        ++count;
        idx = delimiter+1;
      }

      string res = ss.str();
      res.pop_back();
      return res;
    }
};

int main() {
  Solution sol;
  cout << sol.toGoatLatin("I speak Goat Latin") << endl;
  return 0;
}
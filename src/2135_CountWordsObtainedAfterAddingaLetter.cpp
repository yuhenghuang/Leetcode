#include <unordered_set>
#include <local_leetcode.hpp>

class Solution {
  private:
    struct Word {
      uint8_t count[26];

      Word(): count{0} { }

      Word(const string& s): count{0} {
        for (char c : s)
          ++count[c - 'a'];
      }

      Word& operator=(const string& s) {
        memset(count, 0, sizeof(count));

        for (char c : s)
          ++count[c - 'a'];

        return *this;
      }

      bool operator==(const Word& w) const {
        for (int i = 0; i < 26; ++i)
          if (count[i] != w.count[i])
            return false;

        return true;
      }
    };

    struct WordHash {
      size_t operator()(const Word& w) const {
        size_t val = 0;
        for (int i = 0; i < 26; ++i)
          if (w.count[i])
            val = ((val << 5) + val) + w.count[i];

        return val;
      }
    };

    int str2Int(const string& s) {
      int res = 0;
      for (char c : s)
        res |= 1 << (c - 'a');

      return res;
    }

  public:
    int wordCountTLE(vector<string>& startWords, vector<string>& targetWords) {
      // Too general...

      unordered_set<Word, WordHash> s;
      for (auto& w : startWords)
        s.emplace(w);

      int res = 0;
      Word word;

      for (auto& w : targetWords) {
        word = w;
        for (int i = 0; i < 26; ++i)
          if (word.count[i] == 1) {
            word.count[i] = 0;

            if (s.find(word) != s.end()) {
              ++res;
              break;
            }

            word.count[i] = 1;
          }
      }

      return res;
    }

    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
      unordered_set<int> s;
      for (auto& w : startWords)
        s.insert(str2Int(w));

      int res = 0;
      for (auto& w : targetWords) {
        // string as bits
        int b = str2Int(w);

        for (int i = 0; i < 26; ++i)
          if ((b & (1 << i)) && s.find(b ^ (1 << i)) != s.end()) {
            ++res;
            break;
          }
      }

      return res;
    }
};


int main() {
  EXECS(Solution::wordCountTLE);
  EXECS(Solution::wordCount);
  return 0;
}
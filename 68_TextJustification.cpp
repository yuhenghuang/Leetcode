#include <local_leetcode.hpp>

class Solution {
  private:
    int ceil_div(int a, int b) {
      return a / b + (a % b ? 1 : 0);
    }

  public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
      const int n = words.size();

      vector<string> res;

      for (int i = 0; i < n;) {
        string& line = res.emplace_back(maxWidth, ' ');

        // copy the leftmost word
        auto iter = copy(words[i].begin(), words[i].end(), line.begin());

        // remaining spaces after copying first word
        const int m = maxWidth - words[i].size();

        int p = 0; // count of letters

        int j = i;
        for (int k = 0; k <= m;) {
          p += words[j].size();
          ++j;

          if (j < n) [[ likely ]]
            k += 1 + words[j].size();
          else
            break;
        }

        // j - i - 1 spaces for j - i - 1 words in last line
        int q = j == n ? (j - i - 1) : (maxWidth - p);

        for (int k = i + 1; k < j; ++k) {
          int d = ceil_div(q, j - k);

          iter += d; // skip d spaces
          q -= d; // decrement spaces by d

          // copy word and update iterator to the end of the copied word
          iter = copy(words[k].begin(), words[k].end(), iter);
        }

        i = j;
      }

      return res;
    }
};


int main() {
  EXECS(Solution::fullJustify);
  return 0;
}
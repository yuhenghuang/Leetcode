#include <local_leetcode.hpp>

/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
  private:
    int match(const string& s, const string& p) {
      int m = 0;
      for (int i = 0; i < 6; ++i)
        if (s[i] == p[i])
          ++m;

      return m;
    }

  public:
    void findSecretWord(Master& master, vector<string>& words) {
      const int n = words.size();

      bool seen[n];
      memset(seen, false, sizeof(seen));

      for (int m = 0, i = 0; m < 6;) {
        for (; i < n && seen[i]; ++i);
        seen[i] = true;
        m = master.guess(words[i]);

        for (int j = i + 1; j < n; ++j)
          if (!seen[j]) {
            if (match(words[i], words[j]) != m)
              seen[j] = true;
          }

        // std::cout << "tested numbers " << reduce(seen, seen + n, 0) << std::endl;
      }
    }
};


int main() {
  EXECS(Solution::findSecretWord);
  return 0;
}
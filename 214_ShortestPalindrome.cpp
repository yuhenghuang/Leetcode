#include <local_leetcode.hpp>

#define M 13UL

class Solution {
  private:
    template <class Iterator>
    size_t hash(Iterator first, Iterator last) {
      size_t val = 0;
      for (; first != last; ++first)
        val = val * M + (*first - 'a');

      return val;
    }

    template <class Iterator, class Tp, class UnaryOperation>
    void iota(Iterator first, Iterator last, Tp value, UnaryOperation unary_op) {
      static_assert(std::is_base_of<
        std::forward_iterator_tag, 
        typename std::iterator_traits<Iterator>::iterator_category
      >::value);
      static_assert(std::is_convertible<Tp, typename std::iterator_traits<Iterator>::value_type>::value);

      for (; first != last; ++first) {
        *first = value;
        value = unary_op(value);
      }
    }

    // i: center of the palindrome
    bool isPalindromic(int i, const string& s) {
      int j = i / 2;
      int k = j + i % 2;

      while (j >= 0)
        if (s[j--] != s[k++])
          return false;

      return true;
    }

  public:
    string shortestPalindromeHash(string s) {
      const int n = s.size();

      if (n == 0)
        return s;

      size_t left = hash(s.begin(), s.begin() + (n - 1) / 2 + 1);
      size_t right = hash(s.rbegin(), s.rbegin() + (n - ((n - 1) / 2 + (n % 2 == 0))));

      if (left == right && isPalindromic(n - 1, s))
        return s;

      vector<size_t> powers((n+1) / 2);
      iota(powers.begin(), powers.end(), 1UL, [](const size_t& x) { return x * M; });

      for (int i = n - 2; i >= 0; --i) {
        int j = i / 2; // back of the first half of the palindrome
        int k = j + (i % 2); // front of the second half of the palindrome

        // center at odd index
        if (i % 2) {
          // subtract the value of the rightmost char 
          left -= (s[j+1] - 'a') * powers[(n+1) / 2 - j - 2];

          // mulply by M to match with hash value of left
          // avoid modular division
          right = (right - (s[k + j + 1] - 'a') * powers.back()) * M;
        }
        // at even index
        else 
          right = (right - (s[k + j + 1] - 'a') * powers.back()) * M + (s[k] - 'a') * powers[(n+1)/2 - j - 1];

        if (left == right && isPalindromic(i, s))
          return string(s.rbegin(), s.rbegin() + (n - (k + j + 1))) + s;
      }

      // not used, to silence compiler
      return "";
    }

    string shortestPalindrome(string _s) {
      const int n = _s.size();

      if (n == 0)
        return _s;

      string s;
      s.reserve(n * 2);

      for (char c : _s) {
        s.push_back(c);
        s.push_back('#');
      }
      s.pop_back();

      // radius of longest palindrome whose center is at index i
      vector<int> dp(n+1);

      int center;
      int right = -1; // right boarder

      int j = -1; // index of the right boarder of the longest palindrome whose left boarder is the front

      // current center of the palindrome
      for (int i = 0; i <= n; ++i) {
        int r; // radius

        if (i > right)
          r = 1;
        else 
          r = min(right - i + 1, dp[2 * center - right]);

        while (i - r >= 0 && i + r <= (n * 2) && s[i-r] == s[i+r])
          ++r;

        // found palindrome whose left boarder is front
        if (r > i)
          j = (i + r) / 2;

        if (i + r - 1 > right) {
          center = i;
          right = i + r - 1;
        }

        dp[i] = r;
      }

      return string(_s.rbegin(), _s.rbegin() + (n - j - 1)) + _s;
    }
};


int main() {
  EXECS(Solution::shortestPalindrome);
  EXECS(Solution::shortestPalindromeHash);
  return 0;
}

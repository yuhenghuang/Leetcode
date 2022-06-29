#include <local_leetcode.hpp>

typedef long long ll_t;

class Solution {
  public:
    string discountPrices(string sentence, int discount) {

      regex re("(?:^|\\s)\\$(\\d+)(?=$|\\s)");
      sregex_iterator iter(sentence.cbegin(), sentence.cend(), re);
      sregex_iterator eof;

      if (iter == eof)
        return sentence;

      string res;

      auto output_iter = back_inserter(res);
      
      ssub_match lm;
      for (; iter != eof; ++iter) {
        copy(iter->prefix().first, iter->prefix().second, output_iter);

        // c++ regex cannot look behind
        if (!res.empty())
          *output_iter = ' ';

        *output_iter = '$';

        ll_t price = stoll(iter->str(1));
        string num = to_string(price * (100 - discount));

        // pad leading zeros
        while (num.size() < 3)
          num.insert(num.begin(), '0');

        // divided by 100
        num.insert(num.end() - 2, '.');

        copy(num.begin(), num.end(), output_iter);

        lm = iter->suffix();
      }

      copy(lm.first, lm.second, output_iter);

      return res;
    }
};


int main() {
  EXECS(Solution::discountPrices);
  return 0;
}
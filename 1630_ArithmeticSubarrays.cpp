#include <local_leetcode.hpp>

class Solution {
  private:
    typedef pair<int, int> ii_t;

    class Iterator {
      private:
        const vector<ii_t>& vec;
        int l, r;
        int i;

      public:
        Iterator(const vector<ii_t>& vec, int l, int r): vec(vec), l(l), r(r), i(-1) {
          next();
        }

        int get_value() const { return vec[i].first; }

        bool has_next() const { return i < vec.size(); }

        void next() {
          for (++i; has_next() and (vec[i].second < l or vec[i].second > r) ; ++i);
        }
    };

  public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
      const int n = nums.size();
      const int m = l.size();

      vector<ii_t> vec;
      for (int i = 0; i < n; ++i)
        vec.emplace_back(nums[i], i);

      sort(vec.begin(), vec.end());

      vector<bool> res;
      for (int i = 0; i < m; ++i) {
        Iterator iter(vec, l[i], r[i]);

        int prev = iter.get_value(); iter.next();
        int curr = iter.get_value(); iter.next();
        int d = curr - prev;

        bool flag = true;
        for (; iter.has_next(); iter.next()) {
          prev = curr;
          curr = iter.get_value();

          if (d != curr - prev) {
            flag = false;
            break;
          }
        }

        res.push_back(flag);
      }

      return res;
    }
};


int main() {
  EXECS(Solution::checkArithmeticSubarrays);
  return 0;
}
#include <local_leetcode.hpp>

class Solution {
  private:
    template <class Iterator>
    bool all_less_equal(Iterator first1, Iterator last1, Iterator first2) {
      for (; first1 != last1; ++first1, ++first2)
        if (*first1 > *first2)
          return false;

      return true;
    }

  public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
      vector<int> curr(3, 0);

      for (auto& t : triplets)
        if (all_less_equal(t.begin(), t.end(), target.begin()))
          transform(
            curr.begin(), curr.end(), t.begin(), curr.begin(),
            std::function<const int& (const int&, const int&)> (
              static_cast<const int& (*)(const int&, const int&)>(std::max)
            )
          );

      return curr == target;
    }
};


int main() {
  EXECS(Solution::mergeTriplets);
  return 0;
}
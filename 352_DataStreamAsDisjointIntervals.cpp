#include <set>
#include "utils3.hpp"

class SummaryRanges {
  private:
    map<int, int> intervals;

    vector<vector<int>> res;

    void updateResult() {
      res.clear();

      auto iter = intervals.begin();
      auto end = intervals.end();
      for (++iter, --end; iter != end; ++iter)
        res.push_back({iter->first, iter->second});
    }

    struct Comparator {
      bool operator()(const vector<int>& x, const vector<int>& y) const {
        return x.front() < y.front();
      }
    };

  public:
    /** Initialize your data structure here. */
    SummaryRanges() {
      intervals[-2] = -2;
      intervals[10002] = 10002;
    }
    
    void addNum(int val) {
      auto next = intervals.upper_bound(val);
      auto prev = std::prev(next);

      if (prev->second + 1 == val && val + 1 == next->first) {
        prev->second = next->second;
        intervals.erase(next);

        updateResult();
      }
      else if (prev->second + 1 == val) {
        ++prev->second;

        // in-place modifying res
        auto iter = upper_bound(res.begin(), res.end(), vector<int> {val}, Comparator()) - 1;
        ++(iter->back());
      }
      else if (val + 1 == next->first) {
        int tmp = next->second;
        intervals.erase(next);
        intervals.emplace(val, tmp);

        // in-place modifying res
        auto iter = upper_bound(res.begin(), res.end(), vector<int> {val}, Comparator());
        --(iter->front());
      }
      else if (prev->second + 1 < val) {
        intervals.emplace(val, val);

        updateResult();
      }
    }
    
    vector<vector<int>> getIntervals() {
      return res;
    }
};


int main() {
  UFUNCX(
    CTOR(),
    &SummaryRanges::addNum,
    &SummaryRanges::getIntervals
  );
  return 0;
}
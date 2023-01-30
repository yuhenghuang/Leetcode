#include <local_leetcode.hpp>

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


class SummaryRangesNew {
  private:
    vector<vector<int>> itvs;

  public:
    SummaryRangesNew() { }

    void addNum(int val) {
      if (itvs.empty()) {
        itvs.push_back({val, val});
        return;
      }

      typedef vector<vector<int>>::iterator iter_t;

      iter_t next = upper_bound(
        itvs.begin(), itvs.end(), 
        val, 
        [](int i, const vector<int>& j) -> bool { return i < j.front(); }
      );

      iter_t prev = next == itvs.begin() ? next : std::prev(next);

      // only previous interval found
      if (next == itvs.end()) {
        if (prev->back() + 1 == val)
          ++(prev->back());
        else if (prev->back() + 1 < val)
          itvs.push_back({val, val});
      }
      // only next interval found
      else if (next == itvs.begin()) {
        if (val + 1 == next->front())
          --(next->front());
        else if (val + 1 < next->front())
          itvs.insert(next, {val, val});
      }
      else {
        // prev + val + next
        if (prev->back() + 1 == val && val + 1 == next->front()) {
          prev->back() = next->back();
          itvs.erase(next);
        }
        // prev + val
        else if (prev->back() + 1 == val)
          ++(prev->back());
        // val + next
        else if (val + 1 == next->front())
          --(next->front());
        // val not in prev
        else if (prev->back() + 1 < val)
          itvs.insert(next, {val, val});
      }
    }

    vector<vector<int>> getIntervals() {
      return itvs;
    }
};


int main() {
  EXECX(
    CTOR(),
    &SummaryRanges::addNum,
    &SummaryRanges::getIntervals
  );

  EXECX(
    CTOR(),
    &SummaryRangesNew::addNum,
    &SummaryRangesNew::getIntervals
  );
  return 0;
}
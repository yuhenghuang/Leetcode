#include <map>

using namespace std;

class MyCalendar {
  private:
    map<int, int> m;

  public:
    MyCalendar() {
      // dummy begin
      m.emplace(-1, 0);
    }
    
    bool book(int start, int end) {
      /*
      auto i = m.upper_bound(start);
      if (i != m.begin() && (--i)->first < start && i->second <= start) {
        auto j = m.lower_bound(end);
        if (i == --j) {
          m.emplace(start, end);
          return true;
        }
      }
      */

      auto iter = m.lower_bound(end);

      // --iter is always valid due to dummy begin
      if ((--iter)->second <= start) {
        m.emplace(start, end);
        return true;
      }

      return false;
    }
};
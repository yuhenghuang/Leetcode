#include "utils3.hpp"

class MyCalendarTwo {
  private:
    map<int, int> one, two;

    void updateOne(int s, int e) {
      auto it = one.upper_bound(s);

      if (prev(it)->second >= s)
        --it;

      auto ed = one.upper_bound(e);

      pair<int, int> tmp {min(s, it->first), max(e, prev(ed)->second)};

      for (; it != ed; it = one.erase(it)) 
        updateTwo(max(s, it->first), min(e, it->second));

      one.emplace(tmp);
    }

    void updateTwo(int s, int e) {
      if (s < e)
        two.emplace(s, e);
    }

  public:
    MyCalendarTwo() {
      one.emplace(-1, -1);
      two.emplace(-1, -1);

      one.emplace(INT_MAX, INT_MAX);
      two.emplace(INT_MAX, INT_MAX);
    }
    
    bool book(int start, int end) {
      auto iter = two.lower_bound(start);
      if(iter->first < end || prev(iter)->second > start)
        return false;

      updateOne(start, end);

      return true;
    }
};


int main() {
  UFUNCX(
    CTOR(),
    &MyCalendarTwo::book);
  return 0;
}
#include <local_leetcode.hpp>

class ExamRoom {
  private:
    typedef pair<int, int> ii_t;
    typedef typename set<ii_t>::iterator iter_t;

    set<ii_t, greater<ii_t>> m_itv;
    map<int, iter_t> m_seat;

  public:
    ExamRoom(int n) {
      auto p = m_itv.emplace(n+1, 1);
      m_seat.emplace(-1, p.first);
      m_seat.emplace(n, m_itv.end());
    }
    
    int seat() {
      iter_t iter1 = m_itv.begin();

      int i = -iter1->second;

    }
    
    void leave(int p) {
        
    }
};


int main() {
  EXECX(
    CTOR(int),
    &ExamRoom::seat,
    &ExamRoom::leave
  );
  return 0;
}
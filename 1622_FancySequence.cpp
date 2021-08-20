#include "utils3.hpp"

constexpr int ARR_SIZE = 1e5;
constexpr size_t ST_SIZE = (1 << 18) - 1;
constexpr long mod = 1e9 + 7;

class Fancy {
  private:
    struct coefs {
      long multiplier = 1;
      long addend = 0;
    };

    vector<int> arr;
    // segment tree
    // multiplier and addend
    coefs st[ST_SIZE];

    void addAllImpl(int inc, int qs, int qe, int ss, int se, int si) {
      if (qs > se || qe < ss)
        return;
      else if (qs <= ss && se <= qe) {
        st[si].addend = (st[si].addend + inc) % mod;
        return;
      }

      if (ss != se) {
        int sm = ss + (se - ss) / 2;
        addAllImpl(inc, qs, qe, ss, sm, si*2 + 1);
        addAllImpl(inc, qs, qe, sm+1, se, si*2 + 2);
      }
    }


    void multAllImpl(int mult, int qs, int qe, int ss, int se, int si) {
      if (qs > se || qe < ss)
        return;
      else if (qs <= ss && se <= qe) {
        st[si].multiplier = (st[si].multiplier * mult) % mod;
        st[si].addend = (st[si].addend * mult) % mod;
        return;
      }

      if (ss != se) {
        int sm = ss + (se - ss) / 2;
        multAllImpl(mult, qs, qe, ss, sm, si*2 + 1);
        multAllImpl(mult, qs, qe, sm+1, se, si*2 + 2);
      }
    }

    int getIndexImpl(int qi, int ss, int se, int si) {
      if (qi < ss || qi > se)
        return 0;

      int sm = ss + (se - ss) / 2;
      int num = ss == se ? arr[qi] : (
          getIndexImpl(qi, ss, sm, si*2 + 1) +    
          getIndexImpl(qi, sm+1, se, si*2 + 2)
        );

      return (num * st[si].multiplier + st[si].addend) % mod;
    }

  public:
    Fancy() { }
    
    void append(int val) {
      arr.push_back(val);
    }
    
    void addAll(int inc) {
      if (!arr.empty())
        addAllImpl(inc, 0, arr.size() - 1, 0, ARR_SIZE - 1, 0);
    }
    
    void multAll(int m) {
      if (!arr.empty())
        multAllImpl(m, 0, arr.size() - 1, 0, ARR_SIZE - 1, 0);
    }
    
    int getIndex(int idx) {
      return idx >= arr.size() ? -1 : getIndexImpl(idx, 0, ARR_SIZE - 1, 0);
    }
};


int main() {
  UFUNCX(
    CTOR(),
    &Fancy::append,
    &Fancy::addAll,
    &Fancy::multAll,
    &Fancy::getIndex
  );
  return 0;
}
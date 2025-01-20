#include <local_leetcode.hpp>

class Bitset {
  private:
    int size;
    int ones;
    bool flag;
    string data_m;
    string data_s;

  public:
    Bitset(int _size):
      size(_size), ones(0), flag(true), 
      data_m(size, '0'), data_s(size, '1')
    { }
    
    void fix(int idx) {
      if (flag) {
        if (data_m[idx] == '0') {
          data_m[idx] = '1';
          data_s[idx] = '0';
          ++ones;
        }
      }
      else {
        if (data_s[idx] == '0') {
          data_s[idx] = '1';
          data_m[idx] = '0';
          ++ones;
        }
      }
    }
    
    void unfix(int idx) {
      if (flag) {
        if (data_m[idx] == '1') {
          data_m[idx] = '0';
          data_s[idx] = '1';
          --ones;
        }
      }
      else {
        if (data_s[idx] == '1') {
          data_s[idx] = '0';
          data_m[idx] = '1';
          --ones;
        }
      }
    }
    
    void flip() {
      flag = !flag;
      ones = size - ones;
    }
    
    bool all() {
      return ones == size;
    }
    
    bool one() {
      return ones > 0;
    }
    
    int count() {
      return ones;
    }
    
    string toString() {
      return flag ? data_m : data_s;
    }
};


int main() {
  EXECX(
    CTOR(int),
    &Bitset::fix,
    &Bitset::unfix,
    &Bitset::flip,
    &Bitset::all,
    &Bitset::one,
    &Bitset::count,
    &Bitset::toString
  );
  return 0;
}
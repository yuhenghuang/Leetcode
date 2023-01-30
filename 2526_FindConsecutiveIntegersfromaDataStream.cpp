#include <local_leetcode.hpp>

class DataStream {
  private:
    int val, cap;
    int count;

  public:
    DataStream(int value, int k): val(value), cap(k), count(0) { }
    
    bool consec(int num) {
      if (num == val)
        ++count;
      else
        count = 0;

      return count >= cap;
    }
};


int main() {
  EXECX(
    CTOR(int, int),
    &DataStream::consec
  );
  return 0;
}
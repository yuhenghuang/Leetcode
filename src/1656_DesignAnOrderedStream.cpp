#include "utils3.hpp"

class OrderedStream {
  private:
    typedef vector<string>::iterator iter_t;

    vector<string> arr;
    iter_t iter;

  public:
    OrderedStream(int n): arr(n), iter(arr.begin()) { }
    
    vector<string> insert(int idKey, string value) {
      arr[idKey - 1] = value;

      if (iter->empty())
        return {};
      else {
        iter_t bg = iter;
        while (iter != arr.end() && !iter->empty())
          ++iter;
        return {bg, iter};
      }
    }
};


int main() {
  UFUNCX(
    CTOR(int),
    &OrderedStream::insert
  );
  return 0;
}
#include <local_leetcode.hpp>

class SmallestInfiniteSet {
  private:
    int inf;

    set<int> s;

  public:
    SmallestInfiniteSet(): inf(1) { }
    
    int popSmallest() {
      if (!s.empty()) {
        auto iter = s.begin();

        int res = *iter;
        s.erase(iter);

        return res;
      }
      else
        return inf++;
    }
    
    void addBack(int num) {
      if (num < inf)
        s.insert(num);
    }
};


int main() {
  EXECX(
    CTOR(),
    &SmallestInfiniteSet::popSmallest,
    &SmallestInfiniteSet::addBack
  );
  return 0;
}
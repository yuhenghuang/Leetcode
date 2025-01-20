#include <local_leetcode.hpp>

class Vector2D {
  private:
    typedef vector<vector<int>>::iterator iter2d_t;
    typedef vector<int>::iterator iter1d_t;

    iter2d_t iter_2d, end_2d;
    iter1d_t iter_1d;

  void move() {
    while (iter_2d != end_2d && iter_1d == iter_2d->end()) 
      iter_1d = (++iter_2d)->begin();
  }

  public:
    Vector2D(vector<vector<int>>& vec): iter_2d(vec.begin()), end_2d(vec.end()) {
      iter_1d = iter_2d->begin();
    }

    int next() {
      move();
      return *(iter_1d++);
    }

    bool hasNext() {
      move();
      return iter_2d != end_2d;
    }
};


int main() {
  EXECX(
    CTOR(vector<vector<int>>&),
    &Vector2D::next,
    &Vector2D::hasNext
  );
  return 0;
}
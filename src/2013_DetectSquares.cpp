#include <set>
#include "utils3.hpp"

// wrong answers
class DetectSquaresWrong {
  private:
    typedef typename map<int, int>::iterator iter_t;

    map<int, int> row[1001];
    map<int, int> col[1001];

    short res[1001][1001] = {0};

  public:
    DetectSquaresWrong() { }
    
    void add(vector<int> point) {
      int x = point[0];
      int y = point[1];
      
      map<int, int>& r = row[y];
      map<int, int>& c = col[x];

      // point on 90 degree
      // horizontal iterator
      iter_t i = r.begin();
      // vertical iterator
      iter_t j = c.begin();

      while (i != r.end() && j != c.end()) {
        int l = i->first - x;

        if (l < j->first - y)
          ++i;
        else if (l > j->first - y)
          ++j;
        else {
          if (l != 0)
            res[x+l][y+l] += i->second * j->second;
          ++i;
          ++j;
        }
      }

      // ss
      for (i = r.begin(); i != r.end(); ++i)
        if (i->first != x) {
          int l = i->first - x;

          for (int sign : {-1, 1}) {
            j = col[i->first].find(y + l*sign);
            if (j != col[i->first].end())
              res[x][y + l*sign] += i->second * j->second;
          }

        }

      for (j = c.begin(); j != c.end(); ++j)
        if (j->first != y) {
          int l = j->first - y;
          for (int sign : {-1, 1}) {
            i = row[j->first].find(x + l*sign);
            if (i != row[j->first].end())
              res[x + l*sign][y] += i->second * j->second;
          }
        }

      ++r[x];
      ++c[y];
    }
    
    int count(vector<int> point) {
      return res[point[0]][point[1]];
    }
};


class DetectSquares {
  private:
    unordered_map<int, int> row[1001];
    unordered_map<int, int> col[1001];

  public:
    DetectSquares() { }
    
    void add(vector<int> point) {
      int x = point[0];
      int y = point[1];

      ++row[y][x];
      ++col[x][y];
    }
    
    int count(vector<int> point) {
      int x = point[0];
      int y = point[1];

      unordered_map<int, int>& r = row[y];

      int res = 0;
      for (auto& p : col[x])
        if (p.first != y) {
          int l = y - p.first;

          for (int sign : {-1, 1}) {
            int xx = x + sign*l;
            if (r.count(xx) && row[p.first].count(xx))
              res += p.second * r[xx] * row[p.first][xx];
          }
        }

      return res;
    }
};


int main() {
  UFUNCX(
    CTOR(),
    &DetectSquares::add,
    &DetectSquares::count
  );
  return 0;
}
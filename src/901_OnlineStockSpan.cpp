#include <local_leetcode.hpp>

class StockSpanner {
  private:
    // price, days
    stack<pair<int, int>> s;
  public:
    StockSpanner() { }
    
    int next(int price) {
      int res = 1;

      while (!s.empty() && s.top().first <= price) {
        res += s.top().second;
        s.pop();
      }

      s.emplace(price, res);
      return res;
    }
};

int main() {
  EXECX(
    CTOR(),
    &StockSpanner::next
  );
  return 0;
}
#include <stack>
#include <iostream>
using namespace std;

class StockSpanner {
  private:
    stack<pair<int, int>> s;
  public:
    StockSpanner() {
      s = stack<pair<int, int>>();
    }
    
    int next(int price) {
      int res=1;
      while (!s.empty() && s.top().first<=price) {
        res += s.top().second;
        s.pop();
      } 
      s.push(make_pair(price, res));
      return res;
    }
};

int main() {
  StockSpanner span;
  cout << span.next(100) << endl;
  cout << span.next(80) << endl;
  cout << span.next(60) << endl;
  cout << span.next(70) << endl;
  cout << span.next(60) << endl;
  cout << span.next(75) << endl;
  cout << span.next(85) << endl;
  return 0;
}
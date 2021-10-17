#include <set>
#include "utils3.hpp"

class StockPrice {
  private:
    // current timestamp and price
    int t, p;

    // timestamp: price
    unordered_map<int, int> timeline;
    // price, timestamp
    set<pair<int, int>> treeset;

  public:
    StockPrice(): t(0), p(0) { }
    
    void update(int timestamp, int price) {
      if (timestamp >= t) {
        t = timestamp;
        p = price;
      }

      auto iter = timeline.find(timestamp);
      if (iter == timeline.end()) {
        timeline[timestamp] = price;

        treeset.emplace(price, timestamp);
      }
      else if (iter->second != price) {
        treeset.erase({iter->second, timestamp});

        iter->second = price;
        treeset.emplace(price, timestamp);
      }

    }
    
    int current() {
      return p;
    }
    
    int maximum() {
      return prev(treeset.end())->first;
    }
    
    int minimum() {
      return treeset.begin()->first;
    }
};


int main() {
  UFUNCX(
    CTOR(),
    &StockPrice::update,
    &StockPrice::current,
    &StockPrice::maximum,
    &StockPrice::minimum
  );
  return 0;
}
#include <set>
#include "utils3.hpp"

class MovieRentingSystem {
  private:
    typedef pair<int, int> pii;

    // shop, (movie, price)
    vector<unordered_map<int, int>> prices;

    // movie, (price, shop)
    unordered_map<int, set<pii>> inventory;

    // price, shop, movie
    set<tuple<int, int, int>> rented;

  public:
    MovieRentingSystem(int n, vector<vector<int>>& entries): prices(n) {
      for (const vector<int>& t : entries) {
        prices[t[0]][t[1]] = t[2];
        inventory[t[1]].emplace(t[2], t[0]);
      }
    }
    
    vector<int> search(int movie) {
      set<pii>& m = inventory[movie];

      vector<int> res;
      auto iter = m.begin();
      while (res.size() < 5 && iter != m.end())
        res.push_back(iter++->second);

      return res;
    }
    
    void rent(int shop, int movie) {
      int price = prices[shop][movie];

      inventory[movie].erase({price, shop});

      rented.emplace(price, shop, movie);
    }
    
    void drop(int shop, int movie) {
      int price = prices[shop][movie];

      rented.erase({price, shop, movie});

      inventory[movie].emplace(price, shop);
    }
    
    vector<vector<int>> report() {
      vector<vector<int>> res;
      
      auto iter = rented.begin();
      while (res.size() < 5 && iter != rented.end()) {
        res.push_back({get<1>(*iter), get<2>(*iter)});
        ++iter;
      }

      return res;
    }
};


int main() {
  UFUNCX(
    CTOR(int, vector<vector<int>>&),
    &MovieRentingSystem::search,
    &MovieRentingSystem::rent,
    &MovieRentingSystem::drop,
    &MovieRentingSystem::report
  );
  return 0;
}
#include <local_leetcode.hpp>

class Cashier {
  private:
    int n;
    int id;
    double rate;

    // product, price
    unordered_map<int, int> m;

  public:
    Cashier(int _n, int discount, vector<int>& products, vector<int>& prices): n(_n), id(0) {
      rate = (100 - discount) / 100.0;

      for (int i = 0; i < products.size(); ++i)
        m[products[i]] = prices[i];
    }
    
    double getBill(vector<int> product, vector<int> amount) {
      int bill = 0;
      for (int i = 0; i < product.size(); ++i)
        bill += m[product[i]] * amount[i];

      if (++id % n == 0)
        return bill * rate;
      else
        return bill;
    }
};


int main() {
  EXECX(
    CTOR(int, int, vector<int>&, vector<int>&),
    &Cashier::getBill
  );
  return 0;
}
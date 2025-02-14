#include <local_leetcode.hpp>

class ProductOfNumbers {
  private:
    vector<int> prefix;

  public:
    ProductOfNumbers(): prefix{1} { }
    
    void add(int num) {
      if (num == 0)
        prefix = {1};
      else
        prefix.push_back(prefix.back() * num);
    }
    
    int getProduct(int k) {
      if (k >= prefix.size())
        return 0;

      return prefix.back() / prefix[prefix.size() - k - 1];
    }
};


int main() {
  EXECX(
    CTOR(),
    &ProductOfNumbers::add,
    &ProductOfNumbers::getProduct
  );
  return 0;
}
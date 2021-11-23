#include "utils3.hpp"

class MKAverage {
  private:
    int m, k;
    int sum;

    queue<int> q;
    priority_queue<int, vector<int>, less<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;

  public:
    MKAverage(int _m, int _k): m(_m), k(_k) {
      
    }
    
    void addElement(int num) {
      if (q.size() < m) {

      }
      else {
        
      }
    }
    
    int calculateMKAverage() {
      if (q.size() < m)
        return -1;

      
    }
};


int main() {
  UFUNCX(
    CTOR(int, int),
    &MKAverage::addElement,
    &MKAverage::calculateMKAverage
  );
  return 0;
}
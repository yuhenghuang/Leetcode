#include "utils3.hpp"

class SeatManager {
  private:
    priority_queue<int, vector<int>, greater<int>> heap;

  public:
    SeatManager(int n) {
      for (int i = 1; i <= n; ++i)
        heap.push(i);
    }
    
    int reserve() {      
      int i = heap.top();
      heap.pop();

      return i;
    }
    
    void unreserve(int seatNumber) {
      heap.push(seatNumber);
    }
};


int main() {
  UFUNCX(
    CTOR(int),
    &SeatManager::reserve,
    &SeatManager::unreserve
  );
  return 0;
}
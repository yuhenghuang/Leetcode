#include "utils3.hpp"

class MedianFinder {
  private:
    priority_queue<int> front;
    priority_queue<int, vector<int>, greater<int>> back;

  public:
    /** initialize your data structure here. */
    MedianFinder() {
      front.push(INT_MIN);
      back.push(INT_MAX);
    }
    
    void addNum(int num) {
      if (front.top() <= num && num <= back.top()) {
        if (front.size() <= back.size())
          front.push(num);
        else
          back.push(num);
      }
      else if (num < front.top()) {
        if (front.size() > back.size()) {
          back.push(front.top());
          front.pop();
        }

        front.push(num);
      }
      else { // num > back.top()
        if (front.size() < back.size()) {
          front.push(back.top());
          back.pop();
        }

        back.push(num);
      }
    }
    
    double findMedian() {
      if (front.size() > back.size())
        return front.top();
      else if (front.size() < back.size())
        return back.top();
      else 
        return static_cast<double>((front.top()) + back.top()) / 2;
    }
};


int main() {
  UFUNCX(
    BIND(),
    &MedianFinder::addNum,
    &MedianFinder::findMedian
  );
  return 0;
}
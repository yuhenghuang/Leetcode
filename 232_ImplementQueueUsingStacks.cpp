#include <local_leetcode.hpp>

class MyQueue {
  private:
    stack<int> in, out;

    void move() {
      if (out.empty()) {
        while (!in.empty()) {
          out.push(in.top());
          in.pop();
        }
      }
    }

  public:
    MyQueue() { }
    
    void push(int x) {
      in.push(x);
    }
    
    int pop() {
      move();

      int res = out.top();
      out.pop();

      return res;
    }
    
    int peek() {
      move();
        
      return out.top();
    }
    
    bool empty() {
      return in.empty() && out.empty();
    }
};


int main() {
  EXECX(
    CTOR(),
    &MyQueue::push,
    &MyQueue::pop,
    &MyQueue::peek,
    &MyQueue::empty
  );
  return 0;
}
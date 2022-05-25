#include <local_leetcode.hpp>

class MyStack {
  private:
    queue<int> q;

  public:
    MyStack() { }
    
    void push(int x) {
      q.push(x);

      for (int i = 0; i + 1 < q.size(); ++i) {
        x = q.front();
        q.pop();
        q.push(x);
      }
    }
    
    int pop() {
      int x = q.front();
      q.pop();
      return x;
    }
    
    int top() { return q.front(); }
    
    bool empty() { return q.empty(); }
};


int main() {
  EXECX(
    CTOR(),
    &MyStack::push,
    &MyStack::pop,
    &MyStack::top,
    &MyStack::empty
  );
  return 0;
}
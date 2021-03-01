#include <unordered_map>
#include <stack>

using namespace std;

class FreqStack {
  private:
    int maxFreq;
  
    unordered_map<int, int> count;
    unordered_map<int, stack<int>*> mapStack;
  
  public:
    FreqStack(): maxFreq(0) { }
    
    void push(int x) {
      int x_cnt = ++count[x];
      
      if (x_cnt > maxFreq)
        maxFreq = x_cnt;
      
      if (mapStack.count(x_cnt) == 0)
        mapStack.emplace(x_cnt, new stack<int>());
      
      stack<int>* s = mapStack[x_cnt];
      s->push(x);
    }
    
    int pop() {
      if (mapStack[maxFreq]->size() == 0 && maxFreq > 0)
        --maxFreq;
      
      stack<int>* s = mapStack[maxFreq];
      
      int res = s->top();
      s->pop();
      --count[res];
      
      return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
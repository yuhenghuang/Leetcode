#include <local_leetcode.hpp>

class FreqStack {
  private: 
    int maxFreq;

    // val, freq
    unordered_map<int, int> freqs;

    // freq, stack
    vector<stack<int>> stacks;
  
  public:
    FreqStack(): maxFreq(0), stacks(1) { }
    
    void push(int x) {
      // frequency of x
      int f = ++freqs[x];
      
      if (f > maxFreq)
        maxFreq = f;
      
      if (f == stacks.size())
        stacks.emplace_back();
      
      stacks[f].push(x);
    }
    
    int pop() {
      if (stacks[maxFreq].empty() && maxFreq > 0)
        --maxFreq;
      
      stack<int>& s = stacks[maxFreq];
      
      int x = s.top(); s.pop();
      
      --freqs[x];
      
      return x;
    }
};


int main() {
  EXECX(
    CTOR(),
    &FreqStack::push,
    &FreqStack::pop
  );
  return 0;
}
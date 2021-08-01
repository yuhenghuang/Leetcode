#include "utils3.hpp"

class BrowserHistory {
  private:
    int i;
    int cap;
    vector<string> history;

  public:
    BrowserHistory(string homepage): i(0), history{homepage}, cap(0) { }
    
    void visit(string url) {
      if (++i == history.size())
        history.push_back(url);
      else
        history[i] = url;

      cap = i;
    }
    
    string back(int steps) {
      i = max(0, i - steps);
      return history[i];
    }
    
    string forward(int steps) {
      i = min(cap, i + steps);
      return history[i];
    }
};


int main() {
  UFUNCX(
    CTOR(string),
    &BrowserHistory::visit,
    &BrowserHistory::back,
    &BrowserHistory::forward
  );
  return 0;
}
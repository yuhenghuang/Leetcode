#include "utils3.hpp"

class AuthenticationManager {
  private:
    // end of life, token
    typedef pair<int, string> pis;

    int duration;
    // living tokens, end of life (exclusive)
    unordered_map<string, int> m;
    priority_queue<pis, vector<pis>, greater<pis>> heap;

  public:
    AuthenticationManager(int timeToLive): duration(timeToLive) { }
    
    void generate(string tokenId, int currentTime) {
      m[tokenId] = currentTime + duration;
      heap.emplace(currentTime + duration, tokenId);
    }
    
    void renew(string tokenId, int currentTime) {
      auto iter = m.find(tokenId);
      if (iter != m.end() && iter->second > currentTime)
          iter->second = currentTime + duration;
    }
    
    int countUnexpiredTokens(int currentTime) {
      while (!heap.empty()) {
        auto p = heap.top();
        if (p.first > currentTime)
          break;

        heap.pop();

        auto iter = m.find(p.second);
        p.first = iter->second;

        if (p.first > currentTime)
          heap.emplace(std::move(p));
        else
          m.erase(iter);
      }

      return heap.size();
    }
};


int main() {
  UFUNCX(
    CTOR(int),
    &AuthenticationManager::generate,
    &AuthenticationManager::renew,
    &AuthenticationManager::countUnexpiredTokens
  );
  return 0;
}
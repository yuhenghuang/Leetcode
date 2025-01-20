#include <local_leetcode.hpp>

class ATM {
  private:
    static constexpr int N = 5;
    static constexpr int banknotes[] = {20, 50, 100, 200, 500};

    long long count[N];

  public:
    ATM(): count{0} { }
    
    void deposit(vector<int>& banknotesCount) {
      for (int i = 0; i < N; ++i)
        count[i] += banknotesCount[i];
    }
    
    vector<int> withdraw(long long amount) {
      vector<int> out(N);

      for (int i = N - 1; i >= 0 && amount > 0; --i) {
        int j = min(amount / banknotes[i], count[i]);

        out[i] = j;
        amount -= banknotes[i] * j;
      }

      if (amount == 0) {
        for (int i = 0; i < N; ++i)
          count[i] -= out[i];

        return out;
      }
      else
        return {-1};
    }
};


int main() {
  EXECX(
    CTOR(),
    &ATM::deposit,
    &ATM::withdraw
  );
  return 0;
}
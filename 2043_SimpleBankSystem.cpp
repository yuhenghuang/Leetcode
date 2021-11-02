#include "utils3.hpp"

class Bank {
  private:
    vector<long long>& balance;

    bool validateAccount(int account) {
      return 0 < account && account <= balance.size();
    }

  public:
    Bank(vector<long long>& _balance): balance(_balance) { }
    
    bool transfer(int account1, int account2, long long money) {
      if (validateAccount(account1) && validateAccount(account2) && balance[account1-1] >= money) {
        balance[account1-1] -= money;
        balance[account2-1] += money;

        return true;
      }

      return false;
    }
    
    bool deposit(int account, long long money) {
      if (validateAccount(account)) {
        balance[account-1] += money;

        return true;
      }

      return false;
    }
    
    bool withdraw(int account, long long money) {
      if (validateAccount(account) && balance[account-1] >= money) {
        balance[account-1] -= money;

        return true;
      }

      return false;
    }
};


int main() {
  UFUNCX(
    CTOR(vector<long long>&),
    &Bank::transfer,
    &Bank::deposit,
    &Bank::withdraw
  );
  return 0;
}
#include <iostream>
using namespace std;

class BlackHorse {
  private:
    double X, Y;
    double res;
  public:
    BlackHorse(double _x): X(_x), res(0) { Y = 0.46-X;}
    void recur(double condP, double entryFee, int pieces) {
      if (condP<1e-10) return;
      if (pieces==50) {
        res += condP * entryFee;
        return;
      }
      res += condP * (0.01 * (entryFee+50) + 0.03 * (entryFee+100) + X * (entryFee+250));
      recur(condP*0.5, entryFee+20, pieces);
      recur(condP*Y, entryFee+20, pieces+1);
    }
  void showAnswer() const { cout << res << endl; }
  void reset(double _x) { X = _x; Y = 0.46-X; res=0; }
};

int main() {
  BlackHorse bs(0.);
  for (double i=0.01; i<0.46; i+=0.01) {
    bs.reset(i);
    bs.recur(1, 20, 0);
    bs.showAnswer();
  }
  return 0;
}
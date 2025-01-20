#include <local_leetcode.hpp>

class ParkingSystem {
  private:
    int slots[3];

  public:
    ParkingSystem(int big, int medium, int small):
      slots{big, medium, small}
    { }
    
    bool addCar(int carType) {
      if (slots[carType - 1] > 0) {
        --slots[carType - 1];
        return true;
      } 
      return false;
    }
};


int main() {
  EXECX(
    CTOR(int, int, int),
    &ParkingSystem::addCar
  );
  return 0;
}
#include <local_leetcode.hpp>

class UndergroundSystem {
  private:
    // interval, (total time, total trips)
    unordered_map<string, pair<int, int>> trips;

    // id, (checkin station, checkin time)
    unordered_map<int, pair<string, int>> onBoard;
  
  public:
    UndergroundSystem() { }
    
    void checkIn(int id, string stationName, int t) {
      onBoard[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
      auto& p = onBoard[id];
      auto& q = trips[p.first + "_" + stationName];
      q.first += t - p.second;
      q.second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
      auto& q = trips[startStation + "_" + endStation];
      return (double) q.first / q.second;
    }
};


int main() {
  EXECX(
    CTOR(),
    &UndergroundSystem::checkIn,
    &UndergroundSystem::checkOut,
    &UndergroundSystem::getAverageTime
  );
  
  return 0;
}
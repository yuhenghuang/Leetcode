#include <vector>
using namespace std;

class Solution {
  public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
      int res=startTime.size();
      for (int i=0; i<startTime.size(); ++i) 
        res -= (startTime[i]<queryTime) | (endTime[i]>queryTime);
      return res;
    }
};
#include <local_leetcode.hpp>

class Solution {
  private:
    class Buildings {
      private:
        // two 64-bit integers to keep track of at most 20 buildings
        // need 32(+-16), i.e. 5 bits for 1 building
        uint64_t first, second;

        template <uint64_t Buildings::* half, class Binary_Operator>
        void transfer_impl(int buildings) {
          static constexpr Binary_Operator op;
          
          this->*half = op(this->*half, 16ULL << (5 * buildings));
        }

        template <class Binary_Operator>
        void transfer_impl(int buildings) {
          // static constexpr Binary_Operator op;

          // choose $first$ or $second$ given index of building
          if (buildings < 10)
            transfer_impl<&Buildings::first, Binary_Operator>(buildings);
          else
            transfer_impl<&Buildings::second, Binary_Operator>(buildings - 10);
        }

      public:
        Buildings() { }

        Buildings(int): first(0) {
          for (int i = 0; i < 10; ++i)
            first = (first << 5) | 16;

          second = first;
        }

        void transfer(const vector<int>& request) {
          // transfer from
          transfer_impl<minus<uint64_t>>(request[0]);
          // transfer to
          transfer_impl<plus<uint64_t>>(request[1]);
        }

        bool operator==(const Buildings& rhs) const {
          return first == rhs.first && second == rhs.second;
        }
    };


  public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
      Buildings target(0);

      int m = requests.size();
      const int M = 1 << m;

      Buildings dp[M];
      dp[0] = target;

      int res = 0;
      for (int b = 1; b < M; ++b) {
        int j = __builtin_ctz(b);

        dp[b] = dp[b ^ (1 << j)];
        dp[b].transfer(requests[j]);

        if (dp[b] == target)
          res = max(res, __builtin_popcount(b));
      }

      return res;
    }
};


int main() {
  EXECS(Solution::maximumRequests);
  return 0;
}
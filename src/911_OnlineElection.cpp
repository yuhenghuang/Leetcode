#include <local_leetcode.hpp>

class TopVotedCandidate {
  private:
    int n;
    vector<int>& times;
    vector<int> leadings;

  public:
    TopVotedCandidate(vector<int>& persons, vector<int>& _times): n(_times.size()), times(_times), leadings(n) {
      // candidate, vote
      unordered_map<int, int> m;

      int vote = 0;
      for (int i = 0; i < n; ++i) {
        int curr = ++m[persons[i]];

        if (curr >= vote) {
          if (curr > vote)
            vote = curr;

          leadings[i] = persons[i];
        }
        else
          leadings[i] = leadings[i - 1];
      }
    }
    
    int q(int t) {
      int i = n - 1 - (lower_bound(times.rbegin(), times.rend(), t, greater<int>()) - times.rbegin());

      return leadings[i];
    }
};


int main() {
  EXECX(
    CTOR(vector<int>&, vector<int>&),
    &TopVotedCandidate::q
  );
  return 0;
}
#include <set>
#include "utils3.hpp"

static unordered_map<string, int> unit {{"minute", 60}, {"hour", 3600}, {"day", 86400}};

class TweetCounts {
  private:
    unordered_map<string, map<int, int>> hash_map;

  public:
    TweetCounts() { }
    
    void recordTweet(string tweetName, int time) {
      ++hash_map[tweetName][time];
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
      int f = unit[freq];
      vector<int> res((endTime - startTime) / f + 1);

      if (hash_map.count(tweetName)) {
        map<int, int>& tree_map = hash_map[tweetName];
        auto iter = tree_map.lower_bound(startTime);
        while (iter != tree_map.end() && iter->first <= endTime) {
          res[(iter->first - startTime) / f] += iter->second;
          ++iter;
        }
      }

      return res;
    }
};


int main() {
  UFUNCX(
    CTOR(),
    &TweetCounts::recordTweet,
    &TweetCounts::getTweetCountsPerFrequency
  );
  return 0;
}
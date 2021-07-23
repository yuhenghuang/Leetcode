#include <set>
#include "utils3.hpp"

class Twitter {
  private:
    typedef typename vector<pair<int, int>>::reverse_iterator rev_iter;
    typedef pair<rev_iter, rev_iter> prr;

    // time
    int t;

    // users(row), posts(column)
    vector<vector<pair<int, int>>> posts;
    // followers(row), followees(column)
    vector<set<int>> followings;

    struct Comparator {
      bool operator()(const prr& x , const prr& y) const {
        return x.first->first < y.first->first;
      }
    };

  public:
    /** Initialize your data structure here. */
    Twitter(): t(0), posts(501), followings(501) {
      for (int i = 1; i < 501; ++i)
        followings[i].insert(i);
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
      posts[userId].emplace_back(t++, tweetId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
      priority_queue<prr, vector<prr>, Comparator> heap;

      for (int followee : followings[userId]) {
        vector<pair<int, int>>& post = posts[followee];
        if (!post.empty())
          heap.emplace(post.rbegin(), post.rend());
      }

      vector<int> res;
      while (res.size() < 10 && !heap.empty()) {
        auto p = heap.top(); heap.pop();

        res.push_back(p.first->second);

        if (++p.first != p.second)
          heap.emplace(std::move(p));
      }

      return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
      followings[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
      followings[followerId].erase(followeeId);
    }
};


int main() {
  UFUNCX(
    CTOR(),
    &Twitter::postTweet,
    &Twitter::getNewsFeed,
    &Twitter::follow,
    &Twitter::unfollow
  );
  return 0;
}
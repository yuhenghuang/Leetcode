#include <unordered_map>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
  private:
    unordered_map<string, size_t> longUrl2ID;
    vector<string> id2longUrl;
  
    string id2ShortUrl(size_t n) {
      char charArr[] = "abcdefghijklmnopqrstuvwxyzABCDEF"
                        "GHIJKLMNOPQRSTUVWXYZ0123456789";
      
      string shortUrl;
      
      while (n) {
        shortUrl.push_back(charArr[n % 62]);
        n /= 62;
      }
      
      return shortUrl;
    }
  
    size_t shortUrl2ID(string shortUrl) {
      size_t id = 0;
      
      for (int i=shortUrl.size()-1; i>=0; --i) {
        id *= 62;
        if (islower(shortUrl[i]))
          id += shortUrl[i] - 'a';
        else if (isupper(shortUrl[i]))
          id += shortUrl[i] - 'A' + 26;
        else
          id += shortUrl[i] - '0' + 52;
      }
      
      return id;
    }
  
  
  public:
  
    Solution() {
      id2longUrl.emplace_back("bad_short_url");
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
      if (longUrl2ID.count(longUrl) == 0) {
        longUrl2ID[longUrl] = id2longUrl.size();
        id2longUrl.push_back(longUrl);
      }
      
      return id2ShortUrl(longUrl2ID[longUrl] - 1);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
      return id2longUrl[shortUrl2ID(shortUrl) + 1];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));


int main() {
  Solution sol;
  string url = "https://leetcode.com/problems/design-tinyurl";

  cout << sol.encode(url) << endl;

  cout << sol.decode(sol.encode(url)) << endl;

  return 0;
}
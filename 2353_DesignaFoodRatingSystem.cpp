#include <local_leetcode.hpp>

class FoodRatings {
  private:
    // food -> (rating, cuisine)
    unordered_map<string, pair<int, string>> foods;

    // cuisine -> (-rating, food)
    // negate rating for sorting
    unordered_map<string, set<pair<int, string>>> cuisines;

  public:
    FoodRatings(vector<string>& _foods, vector<string>& _cuisines, vector<int>& _ratings) {
      for (int i = 0; i < (int) _foods.size(); ++i) {
        string& food = _foods[i];
        string& cuisine = _cuisines[i];
        int rating = _ratings[i];

        foods[food] = {rating, cuisine};

        cuisines[cuisine].emplace(-rating, food);
      }
    }
    
    void changeRating(string food, int newRating) {
      auto& [rating, cuisine] = foods[food];
      set<pair<int, string>>& s = cuisines[cuisine];

      s.erase({-rating, food});

      rating = newRating;
      
      s.emplace(-newRating, food);
    }
    
    string highestRated(string cuisine) {
      return cuisines[cuisine].begin()->second;
    }
};


int main() {
  EXECX(
    CTOR(vector<string>&, vector<string>&, vector<int>&),
    &FoodRatings::changeRating,
    &FoodRatings::highestRated
  );
  return 0;
}

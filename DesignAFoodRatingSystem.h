class FoodRatings {
private:
    unordered_map<string, int> food_ratings;
    unordered_map<string, set< pair<int,string > > > cuisine_ratings;
    unordered_map<string, string> food_belongsto_cuisine;
    
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++) {
            food_ratings[foods[i]] = ratings[i];
            cuisine_ratings[cuisines[i]].insert({-ratings[i], foods[i]});
            food_belongsto_cuisine[foods[i]] = cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string& cuisine = food_belongsto_cuisine.find(food)->second;
        cuisine_ratings[cuisine].erase({-food_ratings[food], food});
        cuisine_ratings[cuisine].insert({-newRating, food});
        food_ratings[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        return cuisine_ratings[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
 
//https://leetcode.com/problems/design-a-food-rating-system/

/* first approach; 73/77 passed; TLE after

class FoodRatings {
private:
    unordered_map<string,int> food_ratings;
    unordered_map<string,set<string>> foods_of_cuisine;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i < foods.size(); i++) {
            food_ratings[foods[i]] = ratings[i];
            foods_of_cuisine[cuisines[i]].insert(foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
        food_ratings[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        int max_rating = 0;
        string best_rated_food = "";
        for(auto& food : foods_of_cuisine[cuisine]) {
            if(max_rating < food_ratings[food]) {
                max_rating = food_ratings[food];
                best_rated_food = food;
            }
        }
        return best_rated_food;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */

*/
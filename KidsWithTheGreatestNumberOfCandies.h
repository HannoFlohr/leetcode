class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result (candies.size(), false);
        int max_in_array = *max_element(candies.begin(), candies.end());
        max_in_array = max_in_array - extraCandies;

        for(size_t i = 0; i<candies.size(); ++i)
            if(candies[i] >= max_in_array)
                result[i] = true;

        return result;
    }
};
//https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

/*class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> result (candies.size(), false);
        int max_in_array = *max_element(candies.begin(), candies.end());

        for(size_t i = 0; i<candies.size(); ++i)
            if(candies[i] + extraCandies >= max_in_array)
                result[i] = true;
                
        return result;
    }
};*/

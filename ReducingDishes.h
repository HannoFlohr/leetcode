class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int sum = 0, total_satisfaction = 0;

        //start from most satisfying dish
        //each step cook dishes n-1..i
        //add satisfaction for dish i to total satisfaction and the total to the sum
        //stop when total satisfaction + dish i <= 0
        for(int i = satisfaction.size()-1; i >= 0 && satisfaction[i] > -total_satisfaction; --i) {
            total_satisfaction += satisfaction[i]; 
            sum += total_satisfaction; 
        }

        return sum;
    }
};
//https://leetcode.com/problems/reducing-dishes/
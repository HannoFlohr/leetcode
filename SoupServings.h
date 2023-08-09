class Solution {
private: 
    double computeProbabilites(int a, int b, vector<vector<double>>& probabilities) {
        if(a <= 0 && b <= 0)
            return 0.5;
        if(a <= 0)
            return 1;
        if(b <= 0)
            return 0;
        if(probabilities[a][b] > 0)
            return probabilities[a][b];

        probabilities[a][b] = 0.25 * (computeProbabilites(a-4, b, probabilities) +  
                                      computeProbabilites(a-3, b-1, probabilities) + 
                                      computeProbabilites(a-2, b-2, probabilities) +
                                      computeProbabilites(a-1, b-3, probabilities));
        return probabilities[a][b];
    }
public:
    double soupServings(int n) {
        //the higher n is, the higher the percentage for a to run out first gets
        //for n>4800 its closer to 1.0 than the 10^-5 limit
        if(n > 4800) 
            return 1.0;

        vector<vector<double>> probabilities (200, vector<double>(200, 0));
        return computeProbabilites( (n+24)/25, (n+24)/25, probabilities);
    }
};
//https://leetcode.com/problems/soup-servings/
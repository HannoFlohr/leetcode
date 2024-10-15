class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> importance (n, 0);
        //count occurrences of each town
        for(vector<int>& road : roads) {
            importance[road[0]]++;
            importance[road[1]]++;
        }
        //sort the towns descending in order of their occurrence
        vector<pair<int,int>> ordered (n);
        for(int i = 0; i < n; ++i) {
            ordered[i] = {importance[i], i};
        }
        sort(ordered.rbegin(), ordered.rend());
        //set importance of each town according to sorted order
        for(auto [_,town] : ordered) {
            importance[town] = n;
            --n;
        }
        //sum up the importance of all roads
        long long sum = 0;
        for(vector<int>& road : roads) {
            sum += importance[road[0]] + importance[road[1]];
        }
        return sum;
    }
};
//https://leetcode.com/problems/maximum-total-importance-of-roads/
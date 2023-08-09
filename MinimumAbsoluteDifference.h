class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());

        vector<vector<int>> min_dif_pairs;
        int min_dif = INT_MAX;

        for(int i = 1; i < arr.size(); ++i)
            min_dif = min(min_dif, arr[i]-arr[i-1]);

        for(int i = 1; i < arr.size(); ++i) 
            if(arr[i]-arr[i-1] == min_dif)
                min_dif_pairs.push_back({arr[i-1], arr[i]});

        return min_dif_pairs;
    }
};
//https://leetcode.com/problems/minimum-absolute-difference/
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](vector<int>& v1, vector<int>& v2) {
            return v1[0] > v2[0] || (v1[0] == v2[0] && v1[1] < v2[1]);
        });

        vector<vector<int>> sorted;
        for(vector<int>& person : people) {
            sorted.insert(sorted.begin() + person[1], person);
        }
        return sorted;
    }
};
//https://leetcode.com/problems/queue-reconstruction-by-height/
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> answer (k,0);
        unordered_map<int, unordered_set<int>> user_minutes;

        for(vector<int>& log : logs) {
            user_minutes[log[0]].insert(log[1]);
        }
        for(auto& it : user_minutes) { 
            answer[it.second.size()-1]++;
        }

        return answer;
    }
};
//https://leetcode.com/problems/finding-the-users-active-minutes/
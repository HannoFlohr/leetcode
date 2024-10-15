class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int,string> m;
        for(int i = 0; i < names.size(); ++i) {
            m[heights[i]] = names[i];
        }

        vector<string> result;
        for(auto it = m.rbegin(); it != m.rend(); ++it) {
            result.push_back(it->second);
        }
        return result;
    }
};
//https://leetcode.com/problems/sort-the-people/
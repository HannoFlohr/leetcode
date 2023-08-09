class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        const int required = req_skills.size();
        unordered_map<int, vector<int>> bitmasks;
        bitmasks.reserve(1<<required);
        bitmasks[0] = {};

        //enumaration of the skills using a map
        unordered_map<string, int> skills;
        for(int i = 0; i < required; ++i) 
            skills[req_skills[i]] = i;
        
        for(int i = 0; i < people.size(); ++i) {
            //build mask for skills of current person
            int skill_mask = 0;
            for(const auto& skill : people[i])
                skill_mask |= 1 << skills[skill];

            /*for each prev bitmask 
                - combine bitmask with current mask
                - add if not existant already
                - if exist but with larger amount of people, replace
            */
            for(auto it = bitmasks.begin(); it != bitmasks.end(); ++it) {
                int combine = it->first | skill_mask;
                if(bitmasks.find(combine) == bitmasks.end() || bitmasks[combine].size() > 1+bitmasks[it->first].size()) {
                    bitmasks[combine] = it->second;
                    bitmasks[combine].push_back(i);
                }
            }
        }

        return bitmasks[(1<<required) - 1];
    }
};
//https://leetcode.com/problems/smallest-sufficient-team/
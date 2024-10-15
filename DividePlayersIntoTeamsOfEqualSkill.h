class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int teamskill = skill[0] + skill.back();
        long long chemistry = 0;

        for(int front = 0, back = skill.size()-1; front < back; ++front, --back) {
            if(skill[front] + skill[back] != teamskill)
                return -1;

            chemistry += skill[front] * skill[back];
        }

        return chemistry;
    }
};
//https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/
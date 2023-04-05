class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int light = 0, heavy = people.size()-1, boats_needed = 0;

        while(light <= heavy) {
            if(people[light] + people[heavy] <= limit)
                light++;
            
            heavy--;
            boats_needed++;
        }

        return boats_needed;
    }
};
//https://leetcode.com/problems/boats-to-save-people/
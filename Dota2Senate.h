class Solution {
public:
    string predictPartyVictory(string senate) {
        const int senate_size = senate.size();
        int r, d;
        queue<int> q_r, q_d;

        for(int i = 0; i < senate_size; ++i)
            senate[i] == 'R' ? q_r.push(i) : q_d.push(i);
    
        while(!q_r.empty() && !q_d.empty()) {
            r = q_r.front(); q_r.pop();
            d = q_d.front(); q_d.pop();
        
            if(r < d)
                q_r.push(r + senate_size);
            else
                q_d.push(d + senate_size);
        }
    
        return q_r.size() > q_d.size() ? "Radiant" : "Dire";
    }
};
//https://leetcode.com/problems/dota2-senate/
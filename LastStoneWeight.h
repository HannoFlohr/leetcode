class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q (stones.begin(), stones.end());
        int x, y;

        while(q.size() > 1) {
            y = q.top(); q.pop();
            x = q.top(); q.pop();
            
            if(x != y) 
                q.push(y-x);
        }

        return q.empty() ? 0 : q.top();    
    }
};
//https://leetcode.com/problems/last-stone-weight/
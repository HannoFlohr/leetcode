class Solution {
private:
    const int LIMIT = 6000;
public:
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        if(x == 0) {
            return 0;
        }

        //create visited vectors for possible position and the cases visited from forward or backward
        vector<bool> visited_forward (LIMIT, false);
        vector<bool> visited_backward (LIMIT, false);
        for(int f : forbidden) {
            visited_forward[f] = true;
            visited_backward[f] = true;
        }
        visited_forward[0] = true;
        visited_backward[0] = true;

        //bfs search for possible jumps
        int jumps = 0, qsize, cur, forward, backward;
        bool jumped_backward_last;
        queue<pair<int,bool>> q;
        q.push({0,false});
        while(!q.empty()) {
            qsize = q.size();
            while(qsize-- > 0) {
                cur = q.front().first; 
                jumped_backward_last = q.front().second;
                q.pop();

                if(cur == x) {
                    return jumps;
                }

                //jump forward
                forward = cur + a;
                if(forward < LIMIT && !visited_forward[forward]) {
                    q.push({forward,false});
                    visited_forward[forward] = true;
                }

                //jump backward if possible
                if(jumped_backward_last) {
                    continue;
                }
                backward = cur - b;
                if(backward > 0 && !visited_backward[backward]) {
                    q.push({backward,true});
                    visited_backward[backward] = true;
                }
            }

            ++jumps;
        }

        return -1;
    }
};
//https://leetcode.com/problems/minimum-jumps-to-reach-home/
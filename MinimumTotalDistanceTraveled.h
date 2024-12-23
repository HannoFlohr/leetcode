class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int robots = robot.size(), factories = factory.size();
        //dp(r,f) : minimum total distance for robot r using factory f
        vector<vector<long long>> dp (robots+1, vector<long long>(factories+1)); 
        //base: no factories, infinite distance
        for(int i = 0; i < robots; ++i) 
            dp[i][factories] = LLONG_MAX;

        //each factory
        for(int f = factories-1; f >= 0; --f) {
            long long distance = 0;
            deque<pair<int, long long>> q; //robot, min distance
            q.push_back({robots, 0});

            //each robot
            for(int r = robots-1; r >= 0; --r) {
                //add distance robot r to factory f
                distance += abs(robot[r] - factory[f][0]); 
                //remove robots that exceed the capacity of the current factory
                while(!q.empty() && q.front().first > r + factory[f][1])
                    q.pop_front();
                //remove robots with too large distances from the queue
                while(!q.empty() && q.back().second >= dp[r][f+1] - distance)
                    q.pop_back();
                //add robot and distance to current factory to queue
                q.push_back({r, dp[r][f+1] - distance});
                //min distance for current state
                dp[r][f] = q.front().second + distance;
            }
        }

        return dp[0][0];
    }
};
//https://leetcode.com/problems/minimum-total-distance-traveled/
class Solution {
private: 
    bool canReachDestination(const vector<int>& dist, const double hour, int speed) {
        double time_needed = 0;
        for(int i = 0; i < dist.size()-1; ++i)
            time_needed += ((dist[i] + speed - 1) / speed);

        time_needed += ((double)dist.back() / speed);
        return time_needed <= hour;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        if(hour <= (double)(dist.size()-1))
            return -1;

        int low = 1, mid, high = 1e9;
        while(low < high) {
            mid = (low+high)/2;

            if(canReachDestination(dist, hour, mid))
                high = mid;
            else
                low = mid+1;
        }

        return high;
    }
};
//https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
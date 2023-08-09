class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(), batteries.end());

        long long sum = accumulate(batteries.begin(), batteries.end(), 0LL); 
        int charged = 0, bsize = batteries.size();

        //in each step compare max battery with the average value of the remaining batteries
        //if max is bigger than the average, one computer is charged with this battery all the time
        //-> remove from sum and check smaller batteries
        while(batteries[bsize - 1 - charged] > sum / (n - charged)) { 
            sum -= batteries[bsize - 1 - charged]; 
            ++charged;
        }
        //at this point we exhausted all batteries that can be used to charge one computer all the time
        //thus 'sum' remaining battery charge can be used to charge the remaining 'n-charged' computers
        return sum / (n - charged);
    }
};
//https://leetcode.com/problems/maximum-running-time-of-n-computers/
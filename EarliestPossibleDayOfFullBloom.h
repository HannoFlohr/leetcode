class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int,int>> duration(n);
        
        for(int i=0; i<n; i++) {
            duration[i].first = -growTime[i];
            duration[i].second = plantTime[i];
        }
        
        sort(duration.begin(), duration.end());
        
        int cur=0, total=0;
        for(int i=0; i<n; i++) {
            total = max(total, cur + duration[i].second - duration[i].first);
            cur += duration[i].second;
        }
        return total;
    }
};
//https://leetcode.com/problems/earliest-possible-day-of-full-bloom/
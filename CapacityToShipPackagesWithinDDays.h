class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = *max_element(weights.begin(), weights.end());
        int right = 500 * 5 * 1e4;
        int mid, days_needed, current;

        while(left < right) {
            mid = left + (right - left) / 2;
            days_needed = 1;
            current = 0;

            for(size_t i=0; i<weights.size() && days_needed <= days; current += weights[i++]) 
                if(current + weights[i] > mid) {
                    current = 0;
                    days_needed++;
                }

            if(days_needed > days) 
                left = mid+1;
            else
                right = mid;
        }

        return left;
    }
};
//https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
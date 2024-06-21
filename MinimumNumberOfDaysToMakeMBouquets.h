class Solution {
private: 
    bool f(vector<int>& bloomDay, int m, int k, int day) {
        int count, total = 0;

        for(int i = 0; i < bloomDay.size(); ++i) {
            count = 0;
            while(i < bloomDay.size() && count < k && bloomDay[i] <= day) {
                ++count;
                ++i;
            }

            if(count == k) {
                ++total;
                --i;
            }
            if(total >= m) {
                return true;
            }
        }

        return false;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long)m*k > bloomDay.size()) {
            return -1;
        }

        int low = 1, high = 1e9, mid;
        while(low < high) {
            mid = low + (high - low) / 2;
            if(f(bloomDay, m, k, mid)) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};
//https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
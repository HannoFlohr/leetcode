class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(), amount.end());
        
        int count = 0;
        while(amount.back() != 0) {
            --amount.back();
            if(amount[1] > 0)
                --amount[1];
            ++count;

            sort(amount.begin(), amount.end());    
        }

        return count;
    }
};
//https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/
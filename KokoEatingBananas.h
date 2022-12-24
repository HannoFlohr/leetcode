class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if(h == piles.size()) return *max_element(piles.begin(), piles.end());

        int left = 1, mid, right = *max_element(piles.begin(), piles.end()), count;
        while(left < right) {
            mid = left + (right - left) / 2;
            count = 0;

            for(int &p : piles)
                count += (p + mid - 1) / mid;

            if(count > h)
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
};
//https://leetcode.com/problems/koko-eating-bananas/
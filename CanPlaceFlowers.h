class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int can_be_placed = 0, count = 1;
    
        for(int i=0; i<flowerbed.size(); ++i) {
            if(flowerbed[i] == 0) 
                count++;
            else {
                can_be_placed += (count-1)/2;
                count = 0;
            }
        }

        return (can_be_placed + count/2) >= n;
    }
};
//https://leetcode.com/problems/can-place-flowers/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) {
            return false;
        }

        map<int,int> frequency;
        for(int i : hand) {
            frequency[i]++;
        }
        for(auto [num,_] : frequency) {
            if(frequency[num] == 0) {
                continue;
            }
            for(int i = groupSize-1; i >= 0; --i) {
                if((frequency[num + i] -= frequency[num]) < 0) {
                    return false; 
                }
            }
        } 
    
        return true;
    }
};
//https://leetcode.com/problems/hand-of-straights/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;

        map<int,int> freq;
        for(auto &i : hand)
            freq[i]++;

        for(auto &f : freq) {
            if(freq[f.first] == 0) continue;

            for(int i = groupSize-1; i >= 0; i--)
                if((freq[f.first + i] -= freq[f.first]) < 0)
                    return false; 
        } 
    
        return true;
    }
};
//https://leetcode.com/problems/hand-of-straights/
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int jewels_found = 0;
        
        for(char &c : jewels)
            jewels_found += count(stones.begin(), stones.end(), c);
        
        return jewels_found;
    }
};
//https://leetcode.com/problems/jewels-and-stones/

/*

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int jewels_found = 0;
        
        unordered_set<char>  is_jewel (jewels.begin(), jewels.end());
        
        for(char &c : stones)
            if(is_jewel.count(c))
                jewels_found++;
        
        return jewels_found;
    }
};

*/
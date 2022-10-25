class Solution {
private:
    int maxLength(vector<bitset<26>>& bits, bitset<26> bs, int index) {
        int result = bs.count();
        for(int i=index; i<bits.size(); i++)
            if( !(bits[i] & bs).any() ) //check if any equal letters are contained; skip if there are
                result = max(result, maxLength(bits, bs | bits[i], i+1));
        
        return result;
    }
    
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> bits;
		
		//make bitset for each input string and if valid add to candidates 'bits'
        for(const auto &s : arr) {
            bitset<26> bs;
            for(const auto &c : s)
                bs.set(c - 'a');
            if(bs.count() == s.size())
                bits.push_back(bs);
        }
        
        return maxLength(bits, bitset<26>(), 0);
    }
};
//https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/

/*
below: straightforward DFS approach
above: optimized DFS using a bitmask for comparisons

class Solution {
public:
    int maxLength(vector<string>& arr, string str="", int index=0) {
        unordered_set<char> s (str.begin(), str.end());
        if(s.size() != str.size())
            return 0;
        
        int result = str.size();
        for(int i=index; i<arr.size(); i++)
            result = max(result, maxLength(arr, str+arr[i], i+1)); 
        
        return result;
    }
};
*/
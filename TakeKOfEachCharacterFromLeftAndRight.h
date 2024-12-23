class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size(), take = n;
        vector<int> count (3,0);

        //count chars in s
        for(char c : s) 
            ++count[c-'a'];
        //check if solution is possible
        for(int c : count)
            if(c < k)
                return -1;

        //compute how many steps needed
        for(int i = 0, j = 0, window_size = 0; i < n; ++i) {
            --count[s[i]-'a'];
            ++window_size;

            while(count[s[i]-'a'] < k) {
                ++count[s[j]-'a'];
                ++j;
                --window_size;
            }

            take = min(take, n-window_size);
        }

        return take;
    }
};
//https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/
class Solution {
public:
    int minimumDeletions(const string& s) {
        int length = s.length(), count_b = 0;
        vector<int> dp (length+1);

        for(int i = 0; i < length; i++) {
            if(s[i] == 'a') {
                //either remove current 'a' 
                //or keep current 'a' and remove all 'b' before 
                dp[i+1] = min(dp[i]+1, count_b);
            }
            else {
                dp[i+1] = dp[i];
                ++count_b;
            }
        }
        
        return dp[length];
    }
};
//https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/

/* first approach: recursive two pointer; 7/157 passed, TLE afterwards

class Solution {
private:
    void minimumDeletions(const string& s, int left, int right, int deletions, int& min_deletions) {
        while(left < right && s[left] == 'a')
            ++left;
        while(right >= left && s[right] == 'b')
            --right;

        if(left >= right) {
            min_deletions = min(min_deletions, deletions);
            return;
        }

        minimumDeletions(s, left+1, right, deletions+1, min_deletions);
        minimumDeletions(s, left, right-1, deletions+1, min_deletions);
    }
public:
    int minimumDeletions(const string& s) {
        int min_deletions = INT_MAX;
        minimumDeletions(s, 0, s.size()-1, 0, min_deletions);
        return min_deletions;
    }
};

*/
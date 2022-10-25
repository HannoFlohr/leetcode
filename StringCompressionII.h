class Solution {
private:
    const static int N = 125;
    int n;
    string s;
    //dp[start][k] means minimal coding size for substring s[start:], removing at most k chars 
    int dp[N][N];
    
    inline int digitLen(int x) {
        return x==1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3;
    }
    
    int solve(int start, int k) {
        if(k < 0) return N; //invalid
        if(start >= n || n-start <= k) return 0; //empty
        
        int &result = dp[start][k];
        if(result != -1) return result;
        result = N;
        
		//try to make s[start:i] as a group, all chars in this group should be the same
		//so we have to keep the most chars in this range and remove others	
		int count [26] = {0};
        for(int i=start, most=0; i<n; i++) {
            most = max(most, ++count[s[i] - 'a']); 
            result = min(result, 1 + digitLen(most) + solve(i + 1, k - (i - start + 1 - most)));
        }
        
        return result;
    }
    
public:
    int getLengthOfOptimalCompression(string _s, int k) {
        memset(dp, -1, sizeof(dp));
        s = _s;
        n = s.size();
        return solve(0, k);
    }
};
//https://leetcode.com/problems/string-compression-ii/
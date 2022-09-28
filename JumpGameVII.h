class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size(), last = 0;
        vector<bool> dp (n,false); //dp[i] true if i is reachable from start
        dp[0] = true;
        
        for(int i=1; i<n; i++) { 
            //check dp[i-maxJump, .., i-minJump] if at least one of those are true: i reachable
            if(i >= minJump)    last += dp[i-minJump];
            if(i > maxJump)     last -= dp[i-maxJump-1]; 
            
            //true if reachable and '0' 
            dp[i] = last>0 && s[i] == '0';   
        }
        
        return dp[n-1];
    }
};
//https://leetcode.com/problems/jump-game-vii/submissions/
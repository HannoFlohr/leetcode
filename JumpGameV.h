class Solution {
private:
    vector<int> m;
    int d;
    
    int dp(vector<int>& arr, int start) {
        if(m[start] != -1) return m[start];
    
        m[start] = 0;
        for(int i=start+1; i<arr.size() && arr[i] < arr[start] && i <= start+d; i++)
            m[start] = max( m[start], 1+dp(arr,i) );
        for(int i=start-1; i>=0 && arr[i] < arr[start] && i >= start-d; i--)
            m[start] = max( m[start], 1+dp(arr,i) );
    
        return m[start];
    }
    
public:
    int maxJumps(vector<int>& arr, int _d) {
        m = vector<int>(arr.size(),-1);
        d = _d;
        
        int result = 0;
        for(int i=0; i<arr.size(); i++) 
            result = max(result, 1+dp(arr, i));
        
        return result;
    }
};
//https://leetcode.com/problems/jump-game-v/
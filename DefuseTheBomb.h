class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        if(k == 0)
            return vector<int> (code.size(),0);

        const int n = code.size();
        vector<int> result (n, 0);
        //parameters for first window
        int start = 1, end = k;
        if(k < 0) {
            k *= -1;
            start = n-k;
            end = n-1;
        }
        //sum of first window
        int sum = 0;
        for(int i = start; i <= end; ++i)
            sum += code[i];
        //sliding window to compute sum for each index
        for(int i = 0; i < n; ++i) {
            result[i] = sum;
            sum -= code[(start++) % n];
            sum += code[(++end) % n];
        }

        return result;
    }
};
//https://leetcode.com/problems/defuse-the-bomb/
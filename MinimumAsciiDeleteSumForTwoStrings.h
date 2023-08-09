class Solution {
private:
    int lcsSum(const string& s1, const string& s2) {
        const int& n = s1.size(), &m = s2.size();
        vector<int> cur (m+1, 0);
        vector<int> next (m+1, 0);

        for(int i = n-1; i >= 0; --i) {
            for(int j = m-1; j >= 0; --j) {
                int x = 0;
                if(s1[i] == s2[j])
                    x = s1[i] + next[j+1];
                else
                    x = max(next[j], cur[j+1]);

                cur[j] = x;
            }
            
            next = cur;
        }

        return next[0];
    }

public:
    int minimumDeleteSum(string s1, string s2) {
        int sum = 0;
        for(auto& c : s1)
            sum += c;
        for(auto& c : s2)
            sum += c;

        return sum - (lcsSum(s1,s2) * 2);
    }
};
//https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
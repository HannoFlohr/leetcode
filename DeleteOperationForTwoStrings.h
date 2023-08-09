class Solution {
public:
    int minDistance(string word1, string word2) {
        const int &n = word1.size(), &m = word2.size();
        vector<int> cur (m+1, 0);
        vector<int> next (m+1, 0);

        for(int i = n-1; i >= 0; --i) {
            for(int j = m-1; j >= 0; --j) {
                int x = 0;
                if(word1[i] == word2[j])
                    x = 1 + next[j+1];
                else
                    x = max(next[j], cur[j+1]);

                cur[j] = x;
            }

            next = cur;
        }

        return word1.length() + word2.length() - (next[0] * 2);
    }
};
//https://leetcode.com/problems/delete-operation-for-two-strings/
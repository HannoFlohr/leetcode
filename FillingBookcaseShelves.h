class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        vector<int> dp (books.size()+1, INT_MAX);
        dp[0] = 0;

        for(int book = 1; book <= books.size(); ++book) { 
            int width = 0, height = 0;
            for(int i = book; i > 0 && width + books[i-1][0] <= shelfWidth; --i) {
                width += books[i-1][0]; 
                height = max(height, books[i-1][1]); 
                dp[book] = min(dp[book], dp[i-1] + height); 
            }
        }

        return dp.back();    
    }
};
//https://leetcode.com/problems/filling-bookcase-shelves/
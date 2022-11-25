class Solution {
public:
    int numTrees(int n) {
        vector<int> trees = vector<int>(n+1,0);
        trees[0] = trees[1] = 1;
        
        //C(n) = C(0)C(n-1) + C(1)C(n-2) + .....+ C(i-1)C(n-i)..... + C(n-1)C(0)
        for(int i=2; i<=n; i++)
            for(int j=1; j<=i; j++)
                trees[i] += (trees[j-1] * trees[i-j]);
        
        return trees[n];
    }
};
//https://leetcode.com/problems/unique-binary-search-trees/
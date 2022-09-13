class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> p (numRows);
        
        for(int i=0; i<numRows; i++) { 
            p[i].resize(i+1);
            p[i][0] = p[i][i] = 1;
            
            for(int j=1; j<i; j++) 
                p[i][j] = p[i-1][j-1] + p[i-1][j];
        }
                
        return p;
    }
};
//https://leetcode.com/problems/pascals-triangle/

/* first attempt using dp approach than erasing zeros, above solution is faster

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> p (numRows+1, vector<int>(numRows+1, 0));
        p[0][0] = 1;
        
        for(int i=1; i<=numRows; i++) 
            for(int j=1; j<=numRows; j++) 
                p[i][j] = p[i-1][j-1] + p[i-1][j];
            
        p.erase(p.begin());
        for(int i=0; i<p.size(); i++) 
            p[i].erase( remove(p[i].begin(), p[i].end(), 0), p[i].end() );
        
        return p;
    }
};

*/
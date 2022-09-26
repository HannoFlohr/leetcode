class Solution {
private:
    int uf [26];

    int find(int n) {
        if(n != uf[n]) 
            uf[n] = find(uf[n]);
        return uf[n];
    }

public:
    bool equationsPossible(vector<string>& equations) {
        for(int i=0; i<26; i++) 
            uf[i] = i;
        
		//pass all "==" equations and union all equal letters together
        for(auto e:equations)
            if(e[1] == '=')
                uf[find(e[0]-'a')] = find(e[3]-'a');
        
		//pass all "!=" equations and return false if a contradicting "==" equation relation was set in step before
        for(auto e:equations)
            if(e[1] == '!' && find(e[0]-'a') == find(e[3]-'a'))
                return false;
        
        return true;        
    }
};
//https://leetcode.com/problems/satisfiability-of-equality-equations/
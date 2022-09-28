class Solution {
public:
    string pushDominoes(string dominoes) {
        dominoes = 'L' + dominoes + 'R';
        
        string result = "";
        for(int i=0, j=1; j<dominoes.length(); j++) {
            if(dominoes[j]=='.') continue;
            
            int middle = j-i-1;
            
            if(i>0) result += dominoes[i];
            
            if(dominoes[i]==dominoes[j]) 
                result += string(middle, dominoes[i]);
            else if(dominoes[i]=='L' && dominoes[j]=='R') 
                result += string(middle, '.');
            else 
                result += string(middle/2, 'R') + string(middle%2, '.') + string(middle/2, 'L');
            
            i = j;
        }
        
        return result;
    }
};
//https://leetcode.com/problems/push-dominoes/
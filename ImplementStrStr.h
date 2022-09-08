class Solution {
    
void kmp(string pattern, int n, vector<int>& lps) {
    lps[0] = 0;
    int len = 0, i = 1;
    while(i<n) {
        if(pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len != 0) 
                len = lps[len-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

//http://jakeboxer.com/blog/2009/12/13/the-knuth-morris-pratt-algorithm-in-my-own-words/
//https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/
public:
    int strStr(string haystack, string needle) {
        const int h_size = haystack.size();
        const int n_size = needle.size();
        
        if(n_size==0) return 0;
        
        vector<int> lps (n_size);  
        kmp(needle, n_size, lps); 
        
        int i=0, j=0; 
        while((h_size - i) >=  (n_size - j)) {
            if(needle[j] == haystack[i]) {
                i++;
                j++;
            }
            
            if(j == n_size) {
                return i-j;
            }
            if(j < h_size && haystack[i] != needle[j]) {
                (j!=0) ? j = lps[j-1] : i++;
            }
        }
        
        return -1;
    }
};
//https://leetcode.com/problems/implement-strstr/

/*
class Solution {
public:
    int strStr(string haystack, string needle) {
        return haystack.find(needle);
    }
};
*/
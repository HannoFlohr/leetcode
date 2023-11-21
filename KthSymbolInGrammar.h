class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1) 
            return 0;
		
        if(k%2 == 0)
            return (kthGrammar(n-1, k/2) == 0) ? 1 : 0;
        return (kthGrammar(n-1, (k+1)/2) == 0) ? 0 : 1;
    }
};
//https://leetcode.com/problems/k-th-symbol-in-grammar/

/*
compare structure with binary tree
- k even: parent is k/2-node in its level
- k odd: parent is (k+1)/2 node in its level 

compute recursively
*/

/* 15//55 test cases passed; Memory Limit Exceeded

class Solution {
public:
    int kthGrammar(int n, int k) {
        vector<int> cur_row (1,0), prev_row(1,0);
    
        while(--n > 0) {
            cur_row.clear();

            for(int i : prev_row) {
                if(i == 0) {
                    cur_row.push_back(0);
                    cur_row.push_back(1);
                }
                else {
                    cur_row.push_back(1);
                    cur_row.push_back(0);
                }
            }

            prev_row = cur_row;
        }

        return cur_row[k-1];
    }
};
*/
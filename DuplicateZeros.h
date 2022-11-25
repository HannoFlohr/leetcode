class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        const int n = arr.size();
        int new_pos = n + count(arr.begin(), arr.end(), 0);
        
        for(int old_pos = n-1; old_pos >= 0; old_pos--) {
            if(--new_pos < n) arr[new_pos] = arr[old_pos];
            if(arr[old_pos]==0 && --new_pos < n) arr[new_pos] = 0;   
        }
    }
};
//https://leetcode.com/problems/duplicate-zeros/

/* solution using extra space and delete afterwards (a lot slower)

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        const int n = arr.size();
        for(int i=0; i<n; i++) 
            if(arr[i] == 0) 
                arr.insert(arr.begin()+(i++), 0);
        
        while(arr.size() > n)
            arr.pop_back();
    }
};

*/
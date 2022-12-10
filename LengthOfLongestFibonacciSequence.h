class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int longest = 0, current, first, second, target;
        unordered_set<int> numbers (begin(arr), end(arr));

        for(int i=0; i<arr.size(); i++) {
            for(int j=i+1; j<arr.size(); j++) {
                first = arr[i], second = arr[j], current = 2;
                target = first + second;

                while(numbers.find(target) != numbers.end()) {
                    current++;
                    
                    first = second;
                    second = target;
                    target = first + second; 
                }
            
                longest = max(longest, current);
            }
        }

        return longest > 2 ? longest : 0;
    }
};
//https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/
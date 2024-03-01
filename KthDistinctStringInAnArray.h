class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> frequency;
        for(string& s : arr) {
            frequency[s]++;
        }

        for(string& s : arr) {
            if(frequency[s] != 1) {
                continue;
            }
            if(--k == 0) {
                return s;
            }
        }

        return "";
    }
};
//https://leetcode.com/problems/kth-distinct-string-in-an-array/
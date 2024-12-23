class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> count;

        for(string& s : arr) {
            ++count[s];
        }

        for(string& s : arr) {
            if(count[s] == 1 && --k == 0) {
                return s;
            }
        }

        return "";
    }
};
//https://leetcode.com/problems/kth-distinct-string-in-an-array/
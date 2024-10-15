class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> prefixes;
        string value, prefix;
        int result = 0;

        for(int n : arr1) {
            value = to_string(n);
            prefix = "";
            for(char c : value) {
                prefix += c;
                prefixes.insert(prefix);
            }
        }

        for(int n : arr2) {
            value = to_string(n);
            prefix = "";
            for(char c : value) {
                prefix += c;
                if(prefixes.contains(prefix))
                    result = max(result, (int)prefix.size());
            }
        }

        return result;
    }
};
//https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/
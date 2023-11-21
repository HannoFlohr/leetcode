class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> divided;
        int i = 0; 
        while(i+k <= s.size()) {
            divided.push_back(s.substr(i, k));
            i += k;
        }

        if(i < s.size()) {
            string sub = s.substr(i);
            while(sub.length() < k) {
                sub += fill;
            }
            divided.push_back(sub);
        }

        return divided;
    }
};
//https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/
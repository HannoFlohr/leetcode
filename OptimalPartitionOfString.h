class Solution {
public:
    int partitionString(string s) { cout << s.size() << endl;
        unordered_map<char,int> chars;
        int partitions = 1;

        for(const auto &c : s) {
            if(chars[c] > 0) {
                partitions++;
                chars.clear();
            }
                
            chars[c]++;
        }

        return partitions;
    }
};
//https://leetcode.com/problems/optimal-partition-of-string/
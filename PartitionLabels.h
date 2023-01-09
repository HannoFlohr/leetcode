class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> result, last (26, -1);

        //set last position for each char;
        for(int i = 0; i < s.size(); i++)
            last[s[i]-'a'] = i;

        for(int i = 0, max_index = INT_MIN, start_index = 0; i < s.size(); i++) {
            //max position of letters seen up to i
            max_index = max(max_index, last[s[i]-'a']);

            //end of partition reached
            if(max_index == i) {
                result.push_back(i - start_index + 1);
                start_index = i+1;
            }
        }

        return result;
    }
};
//https://leetcode.com/problems/partition-labels/
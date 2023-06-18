class Solution {
public:
    int minDeletions(string s) {
        vector<int> frequency(26,0);
        for(const auto& c : s)
            frequency[c-'a']++;
        sort(frequency.rbegin(), frequency.rend());

        int count_delete = 0;
        for(int i = 1; i < frequency.size(); ++i) {
            if(frequency[i] == 0)
                break;

            if(frequency[i] >= frequency[i-1]) {
                int frequency_before_change = frequency[i];
                frequency[i] = max(0, frequency[i-1] - 1); 
                count_delete += frequency_before_change - frequency[i];
            }
        }

        return count_delete;
    }
};
//https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
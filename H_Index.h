class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.empty()) return 0;

        const int n = citations.size();
        vector<int> citation_frequency (n+1, 0);
        for(const auto& c : citations) {
            if(c >= n) citation_frequency[n]++;
            else citation_frequency[c]++;
        }

        int frequency_sum = 0;
        for(int i=n; i>=0; i--) {
            frequency_sum += citation_frequency[i];
            if(frequency_sum >= i)
                return i;
        }

        return -1;
    }
};
//https://leetcode.com/problems/h-index/
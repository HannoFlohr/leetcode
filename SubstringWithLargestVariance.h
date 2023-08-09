class Solution {
public:
    int largestVariance(string s) {
        unordered_set<char> unique (s.begin(), s.end());
        int largest_variance = 0;

        for(const char& a : unique) {
            for(const char& b : unique) {
                int variance = 0; 
                bool has_b = 0, first_b = 0;

                for(char& c : s) {
                    variance += (c == a);
                    if(c == b) {
                        has_b = true;

                        if(first_b && variance >= 0)
                            first_b = false;
                        else if(--variance < 0) {
                            first_b = true;
                            variance = -1;
                        }
                    }

                    largest_variance = max(largest_variance, has_b ? variance : 0);
                } 
            }
        }

        return largest_variance;
    }
};
//https://leetcode.com/problems/substring-with-largest-variance/
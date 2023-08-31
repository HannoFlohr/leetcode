class Solution {
public:
    int bestClosingTime(string customers) {
        int cur_score = 0, max_score = 0, max_score_hour = -1;

        for(int i = 0; i < customers.length(); ++i) {
            cur_score += (customers[i] == 'Y') ? 1 : -1; 

            if(max_score < cur_score) {
                max_score = cur_score;
                max_score_hour = i;
            } 
        }

        return max_score_hour + 1;
    }
};
//https://leetcode.com/problems/minimum-penalty-for-a-shop/

/* first approach looking at penalties in multiple passes
class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.length(), cur_penalty = 0;
        vector<int> penalty (n+1, 0);

        for(int i = n-1; i >= 0; --i) {
            if(customers[i] == 'Y')
                ++cur_penalty;
            penalty[i] = cur_penalty;
        }

        cur_penalty = 0;
        for(int i = 0; i < n; ++i) {
            if(customers[i] == 'N')
                ++cur_penalty;
            penalty[i+1] += cur_penalty;
        }

        int min_penalty = 1e9, min_penalty_hour;
        for(int i = 0; i < n+1; ++i) {
            if(penalty[i] < min_penalty) {
                min_penalty = penalty[i];
                min_penalty_hour = i;
            }
        }

        return min_penalty_hour;
    }
};
*/
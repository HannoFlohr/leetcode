class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        const int n = scores.size();
        int best_team_score = 0;
        vector<int> dp (n); //dp[i] is score of player i + scores of all players younger than i (j<i) with scores of j <= score of i
        vector<pair<int,int>> players (n);
        
        for(size_t i=0; i<n; i++)
            players[i].first = ages[i], players[i].second = scores[i];
        sort(players.begin(), players.end()); 

        for(size_t i=0; i<n; i++) {
            dp[i] = players[i].second;

            for(size_t j=0; j<i; j++) 
                if(players[j].second <= players[i].second)
                    dp[i] = max(dp[i], dp[j] + players[i].second);

            best_team_score = max(best_team_score, dp[i]);
        }

        return best_team_score;
    }
};
//https://leetcode.com/problems/best-team-with-no-conflicts/
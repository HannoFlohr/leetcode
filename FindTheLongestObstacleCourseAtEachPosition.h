class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> longestIncreasingSubsequence;

        for(int i = 0; i < obstacles.size(); ++i) {
            int obstacle = obstacles[i];

            if(longestIncreasingSubsequence.empty() || longestIncreasingSubsequence[longestIncreasingSubsequence.size()-1] <= obstacle) {
                longestIncreasingSubsequence.push_back(obstacle);
                obstacles[i] = longestIncreasingSubsequence.size();
            }
            else {
                int index = upper_bound(longestIncreasingSubsequence.begin(), longestIncreasingSubsequence.end(), obstacle) - longestIncreasingSubsequence.begin();
                longestIncreasingSubsequence[index] = obstacle;
                obstacles[i] = index+1;
            }
        }    

        return obstacles;
    }
};
//https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/
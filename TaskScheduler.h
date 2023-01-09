class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0) return tasks.size();

        vector<int> freq (26,0);
        for(auto &t : tasks)
            freq[t-'A']++;

        int max_count = *max_element(freq.begin(), freq.end());
        int result = (max_count - 1) * (n + 1);
        for(auto &c : freq)
            if(c == max_count)
                result++;

        return max(result, (int)tasks.size());
    }
};
//https://leetcode.com/problems/task-scheduler/
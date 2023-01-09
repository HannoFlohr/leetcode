class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> task_freq;
        for(auto &task : tasks)
            task_freq[task]++;

        int min_rounds = 0;
        for(auto &tf : task_freq) {
            if(tf.second == 1) return -1;
            min_rounds += (tf.second + 2) / 3;
        }

        return min_rounds;
    }
};
//https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

/*
count frequency of jobs

1 -> not possible
2,3 -> 1 step
4,5,6 -> 2 steps
7,8,9 -> 3 steps
10,11,12 -> 4 steps
...

for each frequency add ceil(freq/3) = (freq+2) / 3
*/
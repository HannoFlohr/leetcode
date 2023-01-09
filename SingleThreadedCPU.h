class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int cur_task = 0, cur_task_executed = 0, tasks_to_finish = tasks.size(); 
        long cur_time = 0;
        for(int i=0; i<tasks_to_finish; i++)
            tasks[i].push_back(i);
        sort(tasks.begin(), tasks.end());

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> queued_tasks;
        vector<int> task_order (tasks_to_finish, -1);

        while(cur_task_executed < tasks_to_finish || queued_tasks.size()) {
            if(queued_tasks.empty())
                cur_time = max(cur_time, (long)tasks[cur_task][0]);
            while(cur_task < tasks_to_finish && cur_time >= tasks[cur_task][0]) 
                queued_tasks.push({tasks[cur_task][1], tasks[cur_task++][2]});

            cur_time += queued_tasks.top().first;
            task_order[cur_task_executed++] = queued_tasks.top().second;
            queued_tasks.pop();
        }

        return task_order;
    }
};
//https://leetcode.com/problems/single-threaded-cpu/
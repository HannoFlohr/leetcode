class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjacent (numCourses, vector<int>());
        vector<int> degree (numCourses, 0);
        for(auto &p : prerequisites) {
            adjacent[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }

        queue<int> q;
        for(int i=0; i<numCourses; i++)
            if(degree[i] == 0)
                q.push(i);

        vector<int> schedule;
        while(!q.empty()) {
            schedule.push_back(q.front());

            for(auto &pre : adjacent[q.front()])
                if(--degree[pre] == 0)
                    q.push(pre);
            
            q.pop();
        }

        return schedule.size() == numCourses ? schedule : vector<int>();
    }
};
//https://leetcode.com/problems/course-schedule-ii/

//modification from first course schedule problem  
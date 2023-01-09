class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        while(!q.empty()) {
            for(auto &pre : adjacent[q.front()])
                if(--degree[pre] == 0)
                    q.push(pre);
            
            q.pop();
            numCourses--;
        }

        return numCourses == 0;
    }
};
//https://leetcode.com/problems/course-schedule/

//https://en.wikipedia.org/wiki/Topological_sorting "Kahns algorithm"
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        const int n = profits.size();
        //create and sort vector of all projects
        vector<pair<int,int>> projects (n);
        for(int i = 0; i < n; ++i) {
            projects[i] = {capital[i], profits[i]};
        }
        sort(projects.begin(), projects.end());

        //loop through all projects and select up to k best projects using a max heap
        priority_queue<int> q;
        for(int taken = 0, project = 0; taken < k; ++taken) {
            while(project < n && projects[project].first <= w) {
                q.push(projects[project].second);
                ++project;
            }

            if(q.empty()) {
                break;
            }

            w += q.top();
            q.pop();
        }

        return w;
    }
};
//https://leetcode.com/problems/ipo/
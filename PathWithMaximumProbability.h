class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int,double>>> graph (n);
        for(int i = 0; i < edges.size(); ++i) { 
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
        } 
        //int c=0;for(auto &g : graph) {cout<<(c++)<<"";for(auto &i : g) {cout<<" | "<<i.first<<" "<<i.second<<" | ";}cout<<endl;}

        vector<double> probabilities (n, 0.0);
        probabilities[start] = 1.0;

        queue<int> q;
        q.push(start);

        while(!q.empty()) {
            int cur_node = q.front();
            q.pop();

            for(const auto& [node, probability] : graph[cur_node]) {
                double new_probability = probabilities[cur_node] * probability;

                if(new_probability > probabilities[node]) {
                    probabilities[node] = new_probability;
                    q.push(node);
                }
            }
        }

        return probabilities[end];    
    }
};
//https://leetcode.com/problems/path-with-maximum-probability/
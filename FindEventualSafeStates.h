class Solution {
private:
    bool findSafeNodes(const vector<vector<int>>& graph, int node, vector<bool>& is_safe_node, vector<bool>& is_cycle_node, vector<bool>& visited) {
        if(is_safe_node[node] == true) //already know node is safe
            return true;
        if(is_cycle_node[node] == true) //already know node is in a cycle
            return false;
        
        if(visited[node] == true) { //found new node belonging to a cycle
            is_cycle_node[node] = true;
            return false;
        }

        visited[node] = true; //mark current node visited
        
        //check if any children of the current node are in a cycle; if true the current node is also in that cycle
        for(const int& go_to : graph[node]) { 
            if(!findSafeNodes(graph, go_to, is_safe_node, is_cycle_node, visited)){
                is_cycle_node[node] = true;
                return false;
            }  
        }

        //current node can be marked as safe
        is_safe_node[node] = true;

        return true;;
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<bool> visited (graph.size(), false);
        vector<bool> is_safe_node (graph.size(), false);
        vector<bool> is_cycle_node (graph.size(), false);
        vector<int> result;

        for(int i = 0; i < graph.size(); ++i) 
            if(findSafeNodes(graph, i, is_safe_node, is_cycle_node, visited))
                result.push_back(i);

        return result;
    }
};
//https://leetcode.com/problems/find-eventual-safe-states/
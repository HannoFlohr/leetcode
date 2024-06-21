class Solution {
private: 
    vector<set<int>> graph;
    vector<int> sum_of_distances, nodes_in_subtree;

	/*
	first step:
		post order traversal dfs
		count the nodes in each subtree for all nodes i
		sum up distances to the "parent" nodes 
	second step: 
		pre order traversal dfs
		when moving root from parent to child i, nodes_in_subtree[i] points get 1 closer to root and n - nodes_in_subtree[i] nodes get 1 further to root 
		update distances: distances[i] = distances[root] - nodes_in_subtree[i] + n - nodes_in_subtree[i] 
	*/
    void dfs(int start, int previous, bool first_step) {
        for(int i : graph[start]) {
            if(i == previous) {
                continue;
            }
            if(first_step) {
                dfs(i, start, first_step);
                nodes_in_subtree[start] += nodes_in_subtree[i];
                sum_of_distances[start] += sum_of_distances[i] + nodes_in_subtree[i];
            }
            else {
                sum_of_distances[i] = sum_of_distances[start] - nodes_in_subtree[i] + nodes_in_subtree.size() - nodes_in_subtree[i];
                dfs(i, start, first_step);
            }
        }
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        sum_of_distances = vector<int>(n, 0);
        nodes_in_subtree = vector<int>(n, 1);

        for(auto &e : edges) {
            graph[e[0]].insert(e[1]);
            graph[e[1]].insert(e[0]);
        }

        dfs(0, -1, true);
        dfs(0, -1, false);

        return sum_of_distances;
    }
};
//https://leetcode.com/problems/sum-of-distances-in-tree/

/* using dijkstra min distance; TLE for larger n 
class Solution {
private: 
    int minimum_distance_index(const vector<int>& distance_to, const vector<bool>& visited) {
        int minimum = INT_MAX, index;

        for(int i=0; i<visited.size(); i++)
            if(visited[i] == false && distance_to[i] <= minimum) {
                minimum = distance_to[i];
                index = i;
            }
        
        return index;
    }

    int distancesToAllNodes(const int& start, const vector<vector<int>>& adjacency) {
        const int n = adjacency.size();
        int index;
        vector<int> distance_to (n, INT_MAX);
        vector<bool> visited (n, false);
        distance_to[start] = 0;

        for(int i=0; i<n; i++) {
            index = minimum_distance_index(distance_to, visited);
            visited[index] = true;

            for(int j=0; j<n; j++) 
                if(!visited[j] && adjacency[index][j] && distance_to[index] != INT_MAX 
                    && distance_to[index] + adjacency[index][j] < distance_to[j]) {
                        distance_to[j] = distance_to[index] + adjacency[index][j];
                    }       
        }

        return reduce(distance_to.begin(), distance_to.end());
    }

public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjacency (n, vector<int>(n,0));
        for(auto &e : edges) {
            adjacency[e[0]][e[1]] = 1;
            adjacency[e[1]][e[0]] = 1;
        }

        vector<int> result (n);
        for(int i=0; i<n; i++)
            result[i] = distancesToAllNodes(i, adjacency);
        return result;
    }
};
*/
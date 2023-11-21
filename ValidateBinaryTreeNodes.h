class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> indegree (n, 0);
        for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1) {
                if(++indegree[leftChild[i]] > 1) {
                    return false;
                }
            }
            if(rightChild[i] != -1) {
                if(++indegree[rightChild[i]] > 1) {
                    return false;
                }
            }
        } 

        int zero_degree_node = -1;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                if(zero_degree_node != -1) {
                    return false;
                }
                zero_degree_node = i;
            } 
        }

        if(zero_degree_node == -1) {
            return false;
        }

        int cur;
        vector<bool> visited (n, false);
        queue<int> q;
        q.push(zero_degree_node);
        while(!q.empty()) {
            cur = q.front();
            q.pop();
            
            if(visited[cur]) {
                return false;
            }
            
            visited[cur] = true;

            if(leftChild[cur] != -1) {
                q.push(leftChild[cur]);
            }
            if(rightChild[cur] != -1) {
                q.push(rightChild[cur]);
            }
        }

        for(bool v : visited) {
            if(v ==  false) {
                return false;
            }
        }
        return true;
    }
};
//https://leetcode.com/problems/validate-binary-tree-nodes/
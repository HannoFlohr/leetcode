class TreeAncestor {
private:
    vector<vector<int>> parents; //parents[i][node] contains the 2^i-th parent of node 
    const int LIMIT = 17; //2^16 = 65536 > 5*10^4 -> 16-th parent as max for these constraints

public:
    TreeAncestor(int n, vector<int>& parent) {
        parents.resize(LIMIT, vector<int>(n, -1)); 

        //first parent
        for(size_t i=0; i<n; i++) 
            parents[0][i] = parent[i];

        //2^i-th parents
        for(int i=1; i<LIMIT; i++) 
            for(int height = 0; height < n; height++) {
                int parent_id = parents[i-1][height];
                if(parent_id != -1)
                    parents[i][height] = parents[i-1][parent_id];
            }
    }
    
    int getKthAncestor(int node, int k) { 
        for(size_t i=0; i<LIMIT; i++) {
            //check if correct 2^i for k
            if(k & (1<<i)) {
                node = parents[i][node];
                if(node == -1)
                    return -1;
            }
        }

        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

//https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

/* second approach, using a jump array data structure - passed all testcases, but slower and needs more space
class TreeAncestor {
private:
    vector<vector<int>> jumps_from_node;
    vector<int> height_of_node;

    void traverse(const vector<vector<int>>& tree, int i, int height, vector<int>& path) {
        height_of_node[i] = height;

        for(int h = 1; h <= path.size(); h *= 2)
            jumps_from_node[i].push_back(path[path.size() - h]);

        path.push_back(i);

        for(auto &child : tree[i])
            traverse(tree, child, height+1, path);
        
        path.pop_back();
    }

public:
    TreeAncestor(int n, vector<int>& parent) {
        jumps_from_node.resize(n);
        height_of_node.resize(n);

        vector<vector<int>> tree (n);
        for(size_t i=1; i<n; i++)
            tree[parent[i]].push_back(i);

        vector<int> path = {};
        traverse(tree, 0, 0, path);
    }
    
    int getKthAncestor(int node, int k) { 
        if(k == 0) return node;

        if(height_of_node[node] < k) return -1;

        int height = 1, pos = 0;
        while((height * 2) <= k) {
            height *= 2;
            pos++;
        }

        return getKthAncestor(jumps_from_node[node][pos], k - height);
    }
};
*/

/* first approach, setting up a tree of Nodes and traversing them - TLE for some testcases
class Node {
private:
    int id;
    Node *parent;
public:
    Node(int i) : id(i), parent(nullptr) {}

    const int getId() const { return id; }

    Node* getParent() const { return parent; }

    void setParent(Node* parent) {
        this->parent = parent;
    } 
};

class TreeAncestor {
private:
    vector<Node*> nodes;

public:
    TreeAncestor(int n, vector<int>& parent) {
        nodes.resize(n);

        for(size_t id=0; id<n; id++) {
            Node* node = new Node(id);
            if(id != 0) 
                node->setParent(nodes[parent[id]]);
            nodes[id] = node;
        }    
    }
    
    int getKthAncestor(int node, int k) {
        Node* cur = nodes[node];

        while(k > 0 && cur != nullptr) {
            cur = cur->getParent();
            k--;
        }
            
        return cur != nullptr ? cur->getId() : -1;
    }
};
*/
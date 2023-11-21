class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        map<int,vector<int>> count_indices;

        for(int i = 0; i < mat.size(); ++i) {
            int count = 0;
            for(int x : mat[i]) {
                count += x;
            }
            count_indices[count].push_back(i);
        }

        vector<int> weakest; 
        for(auto& [count, indices] : count_indices) {
            for(int i : indices) {
                weakest.push_back(i);
                if(weakest.size() == k) {
                    return weakest;
                }
            }
        }

        return weakest;
    }
};

//https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        for(int i = 0; i < mat.size(); ++i) {
            mat[i].push_back(i);
        }

        sort(mat.begin(), mat.end());

        vector<int> weakest (k); 
        for(int i = 0; i < k; ++i) {
            weakest[i] = mat[i].back();
        }

        return weakest;
    }
};

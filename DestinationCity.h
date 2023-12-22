class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string,int> out_degree;
        for(vector<string>& path : paths) {
            out_degree[path[0]]++;
            out_degree[path[1]] += 0;
        }

        for(auto& [city,degree] : out_degree) {
            if(degree == 0)
                return city;
        }

        return "not found.. something went wrong";
    }
};
//https://leetcode.com/problems/destination-city/
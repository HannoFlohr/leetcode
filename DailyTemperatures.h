class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<int> indices;
        indices.push(0);
        
        for(int i=1; i<temperatures.size(); i++) {
            while(!indices.empty() && temperatures[i] > temperatures[indices.top()]) {
                result[indices.top()] = i - indices.top();
                indices.pop();
            }

            indices.push(i);
        }

        return result;
    }
};
//https://leetcode.com/problems/daily-temperatures/
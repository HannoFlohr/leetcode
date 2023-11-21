class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> operations;
        int index = 0, cur_number = 1;

        while(index < target.size()) {
            operations.push_back("Push");
            if(target[index] != cur_number) 
                operations.push_back("Pop");
            else 
                index++;
            
            cur_number++;
        }

        return operations;
    }
};
//https://leetcode.com/problems/build-an-array-with-stack-operations/
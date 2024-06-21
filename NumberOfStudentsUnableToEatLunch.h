class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int size = students.size(), served = 0;
        vector<int> count (2,0);

        for(int s : students) {
            count[s]++;
        }
        while(served < size && count[sandwiches[served]] > 0) {
            count[sandwiches[served]]--;
            served++;
        }
        
        return size - served;
    }
};
//https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
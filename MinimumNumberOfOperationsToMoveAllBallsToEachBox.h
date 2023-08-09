class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> operations (boxes.length(), 0);

        //count operations to move from boxes before box i
        for(int i = 0, sum = 0, count = 0; i < boxes.length(); ++i) {
            operations[i] += sum;
            if(boxes[i] == '1')
                count++;
            sum += count;
        }
        //count operations to move from boxes after box i
        for(int i = boxes.length()-1, sum = 0, count = 0; i >= 0; --i) {
            operations[i] += sum;
            if(boxes[i] == '1')
                count++;
            sum += count;
        }

        return operations;      
    }
};
//https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/
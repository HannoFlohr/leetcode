class Solution {
public:
    int largestInteger(int num) {
        string number = to_string(num);
        priority_queue<int> even, odd;

        for(char c : number) {
            int x = c-'0';
            if(x%2 == 0) {
                even.push(x);
            }
            else {
                odd.push(x);
            }
        }

        for(char& c : number) {
            int x = c-'0';
            if(x%2 == 0) {
                c = even.top()+'0';
                even.pop();
            }
            else {
                c = odd.top()+'0';
                odd.pop();
            }
        }

        return stoi(number);
    }
};
//https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long> numbers;

        for(auto &token : tokens) {
            if(token.size() > 1 || isdigit(token[0]))
                numbers.push(stoi(token));
            else {
                auto b = numbers.top(); numbers.pop();
                auto a = numbers.top(); numbers.pop();
                
                switch(token[0]) { 
                    case '+' : a += b; break;
                    case '-' : a -= b; break;
                    case '*' : a *= b; break;
                    case '/' : a /= b; break;
                }

                numbers.push(a);
            }
        }

        return numbers.top();
    }
};
//https://leetcode.com/problems/evaluate-reverse-polish-notation/
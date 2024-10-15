class Solution {
private:
    int doMath(int x, int y, char op) {
        if(op == '+')
            return x + y;
        if(op == '-')
            return x - y;
        return x * y;
    }

public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> results;
        bool is_number = true;

        for(int i = 0; i < expression.length(); ++i) {
            if(isdigit(expression[i]))
                continue;

            is_number = false;

            vector<int> left = diffWaysToCompute(expression.substr(0, i));
            vector<int> right = diffWaysToCompute(expression.substr(i+1));
        
            for(int x : left) {
                for(int y : right) {
                    results.push_back(doMath(x, y, expression[i]));
                }
            }
        }    
    
        if(is_number)
            results.push_back(stoi(expression));

        return results; 
    }
};
//https://leetcode.com/problems/different-ways-to-add-parentheses/
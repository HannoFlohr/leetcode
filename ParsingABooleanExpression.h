class Solution {
private:
    bool parseAnd(vector<bool>& bools) {
        bool result = true;
        for(bool b : bools)
            result &= b;
        return result;
    }

    bool parseOr(vector<bool>& bools) {
        bool result = false;
        for(bool b : bools)
            result |= b;
        return result;
    }

public:
    bool parseBoolExpr(string expression) {
        vector<char> stack;

        for(char c : expression) {
            //skip certain chars
            if(c == ',' || c == '(')
                continue;
            //end of current expression not reached, push on stack
            if(c != ')') {
                stack.push_back(c);
                continue;
            }
            //else: end of current expression reached, evaluate

            //pop all booleans from the stack
            vector<bool> bools;
            while(stack.back() != '&' && stack.back() != '|' && stack.back() != '!') {
                char b = stack.back();
                stack.pop_back();
                if(b == 't')
                    bools.push_back(true);
                if(b == 'f')
                    bools.push_back(false);
            }

            //evaluate according to char at top of stack
            char op = stack.back();
            stack.pop_back();
            if(op == '&') {
                if(parseAnd(bools))
                    stack.push_back('t');
                else
                    stack.push_back('f');
            }
            else if(op == '|') {
                if(parseOr(bools))
                    stack.push_back('t');
                else
                    stack.push_back('f');
            }
            else if(op == '!') {
                if(bools[0] == false)
                    stack.push_back('t');
                else
                    stack.push_back('f');
            }
        }

        return stack.back() == 't';
    }
};
//https://leetcode.com/problems/parsing-a-boolean-expression/
class Solution {
public:
    string solveEquation(string equation) {
        int i = 0, x = 0, c = 0, number, n = equation.size(), left_side = 1, sign;

        while(i < n) {
            sign = 1;
            number = 0;

            if(equation[i] == '=') {
                left_side = -1;
                i++;
            }
            if(equation[i] == '+') {
                sign = 1;
                i++;
            }
            if(equation[i] == '-') {
                sign = -1;
                i++;
            }

            if(isdigit(equation[i])) {
                while(i < n && isdigit(equation[i])) {
                    number = number*10 + equation[i]-'0';
                    i++;
                }

                if(i < n && equation[i] == 'x') {
                    x += left_side * sign * number;
                    i++;
                }
                else 
                    c += left_side * sign * number;
            }
            else {
                x += left_side * sign;
                i++;
            }
        }

        if(x == 0 && c == 0)
            return "Infinite solutions";
        else if(x == 0)
            return "No solution";
        return "x="+to_string(c/x*-1);
    }
};
//https://leetcode.com/problems/solve-the-equation/
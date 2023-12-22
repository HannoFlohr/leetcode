class Solution {
public:
    int countSpecialNumbers(int n) {
        string limit = to_string(n);
        int digits = limit.size(), count = 0;
        vector<bool> digits_used (10, false);
        
        //count special numbers with digits less than the digits of n
        for(int i = 1; i < digits; i++) {
            int n = 1, k = 9;
            for(int j = 0; j < i-1; j++) {
                n *= k;
                --k;
            }
            count += 9 * n; 
        }

        //count for equal digits
        for(int i = 0; i < digits; i++) {
            int smaller_numbers = 0;
            for(int j = 0; j < limit[i]-'0'; j++) {
                if(!digits_used[j]) {
                    ++smaller_numbers;
                }
            }

            if(i == 0 && limit[i] > '0') {
                --smaller_numbers;
            }

            int n = 1, remaining = 10-i-1;
            for(int j = i+1; j < digits; j++) {
                n *= remaining;
                --remaining;
            }
            count += smaller_numbers * n;
            
            if(!digits_used[limit[i]-'0']) {
                digits_used[limit[i]-'0'] = true;
            }
            else {
                return count;
            }
        }

        return count+1;
    }
};
//https://leetcode.com/problems/count-special-integers/

/*second approach: building special numbers up to n using a queue; 105/120 TC passed, TLE after

class Solution {
public:
    int countSpecialNumbers(int n) {
        if(n < 11) {
            return n;
        }

        string limit = to_string(n), num = "";
        int qsize, count = 9;
        queue<string> q;
        for(char digit = '1'; digit <= '9'; digit++) {
            q.push(num+digit);
        }

        while(!q.empty()) {
            qsize = q.size();
            while(qsize--) {
                num = q.front();
                q.pop();

                for(char digit = '0'; digit <= '9'; digit++) {
                    if(num.find(digit) == string::npos) {
                        string next_num = num+digit; //cout <<num <<" "<< next_num<<endl; 
                        if(stoi(next_num) > n) {
                            return count;
                        }
                        q.push(next_num);
                        ++count;
                    }
                }
            }
        }

        return -1;
    }
};
*/

/* first approach: counting non-special numbers and subtracting from total; 94/120 TC passed, TLE after 

class Solution {
private:
    bool isSpecial(int x) {
        vector<int> digits (10,0);
        while(x > 0) {
            if(++digits[x%10] > 1) {
                return false;
            }
            x /= 10;
        }
        return true;
    }

public:
    int countSpecialNumbers(int n) {
        int non_special = 0;
        for(int i = 11; i  <= n; i++) {
            if(!isSpecial(i)) {
                ++non_special;
            }
        }
        return n - non_special;
    }
};

*/
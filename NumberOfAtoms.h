class Solution {
private: 
    void merge(map<string, int>& a, map<string, int>& b, int times) {
        for(pair<string, int> p : b) {
            a[p.first] += p.second * times;
        }
    }

    int parseDigits(string& s, int& i) {
        int j = i;
        while(i < s.size() && isdigit(s[i])) {
            ++i;
        }
        return i == j ? 1 : stoi(s.substr(j, i-j));
    }

    map<string, int> parseUnits(string& s, int& i) {
        map<string, int> count;

        if(s[i] == '(') {
            map<string, int> count_inner = parse(s, ++i);
            int digits = parseDigits(s, ++i);
            merge(count, count_inner, digits);
        }
        else {
            int j = i++;
            while(i < s.size() && islower(s[i])) {
                ++i;
            }
            string atom = s.substr(j, i-j);
            int digits = parseDigits(s, i);
            count[atom] += digits;
        }

        return count;
    }
    
    map<string, int> parse(string& s, int& i) {
        map<string, int> count;
        while(i < s.size() && s[i] != ')') {
            map<string, int> count_units = parseUnits(s, i);
            merge(count, count_units, 1);
        }
        return count;
    }

public:
    string countOfAtoms(string formula) {
        string output;
        int i = 0;
        
        map<string, int> count = parse(formula, i);
        
        for(pair<string, int> p : count) {
            output += p.first;
            if(p.second > 1) {
                output += to_string(p.second);
            }
        }

        return output;
    }
};
//https://leetcode.com/problems/number-of-atoms/
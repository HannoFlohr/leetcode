class Solution {
public:
    string originalDigits(string s) {
        const vector<string> digits = {"zero", "two", "four", "six", "eight", "one", "three", "five", "seven", "nine"};
        const vector<int> numbers = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
        const vector<int> chars = {'z', 'w', 'u', 'x', 'g', 'o', 'r', 'f', 'v', 'i'};
        vector<int> frequency (26, 0);
        string original = "";

        for(char c : s) {
            frequency[c-'a']++;
        }

        for(int i = 0; i < 10; i++) {
            int freq = frequency[chars[i]-'a'];

            for(int j = 0; j < digits[i].size(); j++) {
                frequency[digits[i][j]-'a'] -= freq;
            }
            original += string(freq, numbers[i]+'0');
        }

        sort(original.begin(), original.end());
        return original;
    }
};
//https://leetcode.com/problems/reconstruct-original-digits-from-english/

/*
even digits all have one unique char
for odd digits: use unique chars for the remaining odd digits

zero	z
one		    o
two	    w
three		r/h
four	u
five		f
six	    x	
seven		v
eight	g
nine		i
*/

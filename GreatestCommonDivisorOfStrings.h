class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return (str1 + str2 == str2 + str1) ? str1.substr(0, gcd(str1.size(), str2.size())) : "";
    }
};
//https://leetcode.com/problems/greatest-common-divisor-of-strings/

/*
if a string 'A' divides str1 and str2 both must be of form "A" "AA" "AAA" "AA.."
e.g. str1=AAA str2=AA
therefore str1+str2 == AAAAA == str2+str1 
*/
//faster runtime, but using extra space
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strings;
        for(auto &n : nums) strings.push_back(to_string(n));
        sort(begin(strings), end(strings), [](string& s1, string& s2){ return s1+s2>s2+s1;} );

        if(strings[0] == "0") return "0";

        string number = "";
        for(auto &s : strings)
            number += s;

        return number;
    } 
};

//less space, but higher runtime
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(begin(nums), end(nums), [](int& a, int& b){ return to_string(a)+to_string(b) > to_string(b) + to_string(a);} );

        if(nums[0] == 0) return "0";

        string number = "";
        for(auto &n : nums)
            number += to_string(n);

        return number;
    } 
};

//https://leetcode.com/problems/largest-number/
class Solution {
public:
    int dayOfYear(string date) {
        const vector<short> days_in_month = {31,28,31,30,31,30,31,31,30,31,30,31};
        int dayofyear = 0;
        //count days for months passed
        int month = stoi(date.substr(5,2));
        for(int i = 0; i < month-1; ++i) {
            dayofyear += days_in_month[i];
        }
        //increment if leap year
        if(month > 2) {
            int year = stoi(date.substr(0,4));
            if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
                dayofyear++;
            }
        }
        return dayofyear + stoi(date.substr(8,2));;
    }
};
//https://leetcode.com/problems/day-of-the-year/
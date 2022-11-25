class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        const vector<string> weekdays = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        const vector<int> daysDiffForMonth = {0,3,2,5,0,3,5,1,4,6,2,4};
        if(month < 3) year -= 1;
        return weekdays[(year + (year/4 - year/100 + year/400) + daysDiffForMonth[month-1] + day) % 7];
    }
};
//https://leetcode.com/problems/day-of-the-week/

//https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week#Sakamoto's_methods
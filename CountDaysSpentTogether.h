class Solution {
private:
    int dayInYear(const string& date) {
        const vector<int> daysPerMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int month = stoi(date.substr(0,2));
        int day = stoi(date.substr(3,2));

        int count = 0;
        for(int i = 0; i < month-1; i++) {
            count += daysPerMonth[i];
        }

        return count + day;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int start = dayInYear(max(arriveAlice, arriveBob));
        int end = dayInYear(min(leaveAlice, leaveBob));
        
        if(end < start)
            return 0;
        return end - start + 1;
    }
};
//https://leetcode.com/problems/count-days-spent-together/
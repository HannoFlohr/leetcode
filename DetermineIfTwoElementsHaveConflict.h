class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        return event1[0] <= event2[1] && event2[0] <= event1[1];
    }
};
//https://leetcode.com/problems/determine-if-two-events-have-conflict/

/*class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        int start1 = 0, end1 = 0, start2 = 0, end2 = 0;

        for(int i = 0; i < 5; i++) {
            if(i == 2) {
                continue;
            }

            start1 = start1 * 10 + event1[0][i]-'0';
            end1 = end1 * 10 + event1[1][i]-'0';
            start2 = start2 * 10 + event2[0][i]-'0';
            end2 = end2 * 10 + event2[1][i]-'0';
        }

        if(start1 >= start2 && start1 <= end2 || 
            end1 >= start2 && end1 <= end2 || 
            end2 >= start1 && end2 <= end1 ||
            start2 >= start1 && start2 <= end1) {
            return true;
        }
        
        return false;
    }
};
*/
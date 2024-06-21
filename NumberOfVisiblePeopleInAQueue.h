class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> st;
        vector<int> result (heights.size(), 0);
        int count;

        for(int i = heights.size()-1; i >= 0; --i) {
            //first person in queue cant see anyone infront
            if(st.empty()) {
                result[i] = 0;
                st.push(heights[i]);
                continue;
            }

            //count persons that the person at i hides for all persons j < i
            count = 0;
            while(!st.empty() && heights[i] > st.top()) { 
                count++;
                st.pop();
            }
            //person at i can see all people it hides for all behind them 
            //& the tallest person before them if existing
            result[i] = count;
            if(!st.empty()) {
                result[i]++;
            }

            st.push(heights[i]);
        }

        return result;
    } 
};
//https://leetcode.com/problems/number-of-visible-people-in-a-queue/
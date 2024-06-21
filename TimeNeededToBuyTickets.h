class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int k_tickets = tickets[k], count = 0, i = 0;

        while(i <= k) {
            count += min(tickets[i], k_tickets);
            i++;
        }
        while(i < tickets.size()) {
            count += min(tickets[i], k_tickets-1);
            i++;
        }

        return count;
    }
};
//https://leetcode.com/problems/time-needed-to-buy-tickets/
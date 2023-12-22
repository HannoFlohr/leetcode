class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        int cheap1 = 101, cheap2 = 101;
        for(int p : prices) {
            if(p < cheap1) {
                cheap2 = cheap1;
                cheap1 = p;
            }
            else if(p < cheap2) {
                cheap2 = p;
            }
        }
        return cheap1+cheap2 > money ? money : money-cheap1-cheap2;
    }
};
//https://leetcode.com/problems/buy-two-chocolates/
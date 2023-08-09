class Solution {
private:
    void distribute(const vector<int>& cookies, vector<int>& children, int k, int current, int& unfairness) {
        if(current == cookies.size()) {
            unfairness = min(unfairness, *max_element(children.begin(), children.end()));
            return;
        }

        for(int i = 0; i < k; ++i) {
            children[i] += cookies[current]; 
            distribute(cookies, children, k, current+1, unfairness);
            children[i] -= cookies[current];
        }
    }

public:
    int distributeCookies(vector<int>& cookies, int k) {
        int unfairness = INT_MAX;
        vector<int> children (k, 0);
        distribute(cookies, children, k, 0, unfairness);
        return unfairness;
    }
};
//https://leetcode.com/problems/fair-distribution-of-cookies/
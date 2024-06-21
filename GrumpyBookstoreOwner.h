class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int satisfied_customers = 0, additional_satisfied_customers = 0, max_additional_satisfied_customers = 0;

        for(int i = 0; i < customers.size(); ++i) {
            if(!grumpy[i]) {
                satisfied_customers += customers[i];
            }
            else {
                additional_satisfied_customers += customers[i];
            }

            if(i >= minutes && grumpy[i - minutes]) {
                additional_satisfied_customers -= customers[i - minutes];
            }

            max_additional_satisfied_customers = max(max_additional_satisfied_customers, additional_satisfied_customers);
        } 

        return satisfied_customers + max_additional_satisfied_customers;
    }
};
//https://leetcode.com/problems/grumpy-bookstore-owner/
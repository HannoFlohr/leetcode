class Solution {
private:
    long long costToSwitch(const vector<int>& nums, const vector<int>& cost, int switch_to) {
        long long result = 0LL;
        for(int i = 0; i < nums.size(); ++i)
            result += (long long)abs(nums[i] - switch_to) * cost[i];
        return result;
    }

public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long left = 1, right = 1000000, result = costToSwitch(nums, cost, 1), mid, value1, value2;

        while(left < right) {
            mid = (left+right) / 2;
            value1 = costToSwitch(nums, cost, mid);
            value2 = costToSwitch(nums, cost, mid+1);
            result = min(value1, value2);

            if(value1 < value2)
                right = mid;
            else
                left = mid + 1;

        }

        return result;
    }
};
//https://leetcode.com/problems/minimum-cost-to-make-array-equal/

/* brute force: solves 40/48 test cases

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        const int n = nums.size();
        vector<long long> cost_to_switch_to (n, 0);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                cost_to_switch_to[j] += (long long)abs(nums[i] - nums[j]) * cost[i];
            }
        }

        return *min_element(cost_to_switch_to.begin(), cost_to_switch_to.end());
    }
};

*/
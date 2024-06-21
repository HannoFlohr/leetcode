class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        long long sum = 0;
        set<int> numbers (nums.begin(), nums.end());
        int last_number = 0;

        for(int cur_number : numbers) {
            if(cur_number != last_number+1) {
                int insert_slots = min(k, cur_number - last_number - 1);
                
                long long sum_to_last = 0LL + last_number;
                long long sum_to_cur = sum_to_last + insert_slots; 
                sum_to_last = sum_to_last * (sum_to_last+1) / 2;
                sum_to_cur = sum_to_cur * (sum_to_cur+1) / 2;
                
                sum += (sum_to_cur - sum_to_last);
                k -= insert_slots;
            }

            last_number = cur_number;
        
            if(k == 0) {
                break;
            }
        }

        if(k > 0) {
            long long sum_to_last = 0LL + last_number;
            long long sum_to_cur = sum_to_last + k;
            sum_to_last = sum_to_last * (sum_to_last+1) / 2;
            sum_to_cur = sum_to_cur * (sum_to_cur+1) / 2;
                
            sum += (sum_to_cur - sum_to_last);
        }

        return sum;
    }
};
//https://leetcode.com/problems/append-k-integers-with-minimal-sum/	
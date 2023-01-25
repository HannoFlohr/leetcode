class Solution {
public:
    int countElements(vector<int>& nums) {
        int min_value = INT_MAX, min_value_count, max_value = INT_MIN, max_value_count;
        for(const auto &num : nums) {
            if(min_value > num) {
                min_value = num;
                min_value_count = 1;
            }
            else if(min_value == num)
                min_value_count++;
            
            if(max_value < num) {
                max_value = num;
                max_value_count = 1;
            }
            else if(max_value == num)
                max_value_count++;
        }

        if(min_value == max_value) 
            return 0;
        return nums.size() - min_value_count - max_value_count;
    }
};
//https://leetcode.com/problems/count-elements-with-strictly-smaller-and-greater-elements/

/*
class Solution {
public:
    int countElements(vector<int>& nums) {
        map<int,int> frequency;
        int min_value = INT_MAX, max_value = INT_MIN;
        for(const auto &num : nums) {
            frequency[num]++;
            min_value = min(min_value, num);
            max_value = max(max_value, num);
        }

        if(min_value == max_value) 
            return 0;
        return nums.size() - frequency[min_value] - frequency[max_value];
    }
};
*/
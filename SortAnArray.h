class Solution {
private:
    void merge(vector<int>& nums, int low, int mid, int high) {
        int left = low, right = mid+1, size = high-low+1, i = 0;
        vector<int> sorted(size, 0);

        while(left <= mid && right <= high) {
            sorted[i++] = nums[left] < nums[right] ? nums[left++] : nums[right++];
        }
        while(left <= mid) {
            sorted[i++] = nums[left++];
        }
        while(right <= high) {
            sorted[i++] = nums[right++];
        }

        for(i = 0; i < size; ++i) {
            nums[low+i] = sorted[i]; 
        }
    }

    void mergeSort(vector<int>& nums, int low, int high) {
        if(low >= high) {
            return;
        }
        int mid = (high-low)/2 + low;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        merge(nums, low, mid, high);
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return nums;
    }
};
//https://leetcode.com/problems/sort-an-array/
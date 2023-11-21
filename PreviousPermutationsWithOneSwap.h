class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int i = arr.size()-2, max_index = -1;

        //search from back, find first increasing element of vector
        while(i >= 0 && arr[i] <= arr[i+1]) {
            i--;
        }

        if(i >= 0) {
            max_index = i+1;
            //find index of max element after arr[i] that is also smaller than arr[i]
            for(int j = max_index+1; j < arr.size(); j++) {
                if(arr[max_index] < arr[j] && arr[j] < arr[i]) {
                    max_index = j;
                }
            }

            swap(arr[i], arr[max_index]);
        }

        return arr;
    }
};
//https://leetcode.com/problems/previous-permutation-with-one-swap/
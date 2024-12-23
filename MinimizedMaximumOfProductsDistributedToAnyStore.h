class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, mid,  right = *max_element(quantities.begin(), quantities.end()), sum;

        while(left < right) {
            mid = (left + right) / 2;
            sum = 0;

            for(int q : quantities) 
                sum += (q + mid - 1) / mid;  // ceil(q / mid);
            if(sum > n)
                left = mid + 1;
            else 
                right = mid;
        }

        return left;
    }
};
//https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/
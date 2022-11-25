class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9+7, n = arr.size();
        
        //stores range to next smaller element to left and right for each element
        vector<int> left(n,-1), right(n,n);
        
        vector<int> stack;
        //compute values for left
        for(int i=0; i<n; i++) {
            while(!stack.empty() && arr[i] < arr[stack.back()])
                stack.pop_back();
            
            if(!stack.empty()) 
                left[i] = i - stack.back();
            else
                left[i] = i + 1;
            
            stack.push_back(i);
        }

        stack.clear();
        
        //compute values for right
        for(int i=n-1; i>=0; i--) {
            while(!stack.empty() && arr[i] <= arr[stack.back()])
                stack.pop_back();
            
            if(!stack.empty())
                right[i] = stack.back() - i;
            else
                right[i] = n - i;
            
            stack.push_back(i);
        }

        //sum up contribution for each i; left*right*value;
        int contribution = 0;
        long long product;
        for(int i=0; i<n; i++) {
            product = (left[i] * right[i]) % MOD;
            product = (product * arr[i]) % MOD;
            contribution = (contribution + product) % MOD;
        }
        
        return contribution;
    }
};
//https://leetcode.com/problems/sum-of-subarray-minimums/

/*
idea is to find the contribution for each element i for all subarrays 
to do that we find the range to the next smaller element for each i from left and right side
the contribution is than computed by left[i] * right[i] * element[i], sum for all i 
*/

/* brute force, gives TLE

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9+7;
        int sum = 0, cur;
        
        //subarrays of size 1 -> min is value itself
        for(auto &a : arr) {
            sum += a;
            sum %= MOD;
        }
        
        arr.push_back(INT_MAX); //add dummy at end for comparison min(i, i+1) at end of first iteration of loop
        
        //add min(i, i+1) to the sum, decrement end after each iteration
        for(int end=arr.size()-2; end>=0; end--) 
            for(int start=0; start<end; start++) {
                cur = min(arr[start], arr[start+1]); 
                sum += cur;
                sum %= MOD;
                arr[start] = cur;
            }
        
        return (int)sum;
    }
};

*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> max_sliding_window (nums.size()-k+1);
        deque<int> q;

        for(int i=0; i<nums.size(); i++) {
            if(!q.empty() && q.front() == i - k)
                q.pop_front();

            while(!q.empty() && nums[q.back()] < nums[i])
                q.pop_back();

            q.push_back(i);

            if(i >= k-1)
                max_sliding_window[i-k+1] = nums[q.front()];
        }

        return max_sliding_window;
    }
};
//https://leetcode.com/problems/sliding-window-maximum/

//using monotic queue: https://abitofcs.blogspot.com/2014/11/data-structure-sliding-window-minimum.html
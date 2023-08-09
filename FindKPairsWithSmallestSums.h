class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int,int,int>> q;
        vector<vector<int>> pairs;
        int sum;

        for(int i = 0; i < nums1.size(); ++i) {
            for(int j = 0; j < nums2.size(); ++j) {
                sum = nums1[i] + nums2[j];
                if(q.size() < k)
                    q.push({sum, nums1[i], nums2[j]});
                else if(sum < get<0>(q.top())) {
                    q.pop();
                    q.push({sum, nums1[i], nums2[j]});
                }
                else
                    break;
            }
        }

        while(!q.empty()) {
            pairs.push_back({get<1>(q.top()),get<2>(q.top())});
            q.pop();
        }

        return pairs;
    }
};
//https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
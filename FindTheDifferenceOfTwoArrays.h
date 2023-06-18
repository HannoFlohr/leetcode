class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer (2, vector<int>());
        set<int> set1 (nums1.begin(), nums1.end()), set2 (nums2.begin(), nums2.end());

        set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(answer[0]));
        set_difference(set2.begin(), set2.end(), set1.begin(), set1.end(), back_inserter(answer[1]));

        return answer;
    }
};
//https://leetcode.com/problems/find-the-difference-of-two-arrays/

/*first approach using maps
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> answer (2, vector<int>());
        unordered_map<int,int> freq1, freq2;

        for(const auto& n : nums1) 
            freq1[n]++;
        for(const auto& n : nums2)
            freq2[n]++;

        for(const auto& [num, freq] : freq1)
            if(freq2[num] == 0)
                answer[0].push_back(num);
        for(const auto& [num, freq] : freq2)
            if(freq1[num] == 0)
                answer[1].push_back(num);

        return answer;
    }
};
*/
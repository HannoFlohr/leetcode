class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        const int k = nums.size();

        //pair all numbers with the lists they belong to and sort
        vector<pair<int,int>> numbers;
        for(int i = 0; i < k; ++i) {
            for(int n : nums[i])
                numbers.push_back({n,i});
        }
        sort(numbers.begin(), numbers.end());

        int lists_covered = 0, out = 0;
        vector<int> range = {numbers[0].first, numbers.back().first};
        unordered_map<int,int> lists;
        for(int cur = 0; cur < numbers.size(); ++cur) {
            //update numbers in current range
            if(!lists[numbers[cur].second]++)
                ++lists_covered;
            //check if all lists are covered
            if(lists_covered < k) 
                continue;
            //minimize range as much as possible
            while(lists[numbers[out].second] > 1) 
                --lists[numbers[out++].second];
            //check if new shortest range
            if(range[1] - range[0] > numbers[cur].first - numbers[out].first)
                range = {numbers[out].first, numbers[cur].first};
        }

        return range;
    }
};
//https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/

/*
above: Runtime 97% Memory 55%

below: first attempt using priority queue, clears all cases as well; Runtime 5% Memory 60%


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        const int k = nums.size();

        //fill a priority queue with all numbers in nums and which list they belong to
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        for(int i = 0; i < nums.size(); ++i) {
            for(int x : nums[i]) {
                q.push({x,i});
            }
        }

        //pop from queue until one number from each list was used
        vector<bool> is_list_covered (k, false);
        vector<int> num_in_range (k, 0);
        int lists_covered = 0;
        while(lists_covered < k) {
            auto [num, list] = q.top();
            q.pop(); 

            if(is_list_covered[list] == false) {
                is_list_covered[list] = true;
                ++lists_covered;
            }
            num_in_range[list] = num;
        }

        //initialize the values for the shortest range
        auto minmax = minmax_element(num_in_range.begin(), num_in_range.end());
        int min_in_range = *minmax.first, max_in_range = *minmax.second;
        int range, shortest_range = max_in_range - min_in_range;

        //for all elements remaining in the queue: update the number in range according 
        //to its list then check if the new range is shorter
        while(!q.empty()) {
            auto [num, list] = q.top();
            q.pop();

            num_in_range[list] = num;

            minmax = minmax_element(num_in_range.begin(), num_in_range.end());
            range = *minmax.second - *minmax.first;
            if(range < shortest_range) {
                shortest_range = range;
                min_in_range = *minmax.first;
                max_in_range = *minmax.second;
            }
        }

        return {min_in_range, max_in_range};
    }
};

*/
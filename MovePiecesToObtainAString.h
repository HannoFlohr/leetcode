class Solution {
public:
    bool canChange(string start, string target) {
        int start_index = 0, target_index = 0, n = target.size();

        while(start_index < n || target_index < n) {
            //find non blank indices in start and target
            while(start_index < n && start[start_index] == '_')
                ++start_index;
            while(target_index < n && target[target_index] == '_')
                ++target_index;
            //char can be moved if 
            //- equal char for both indices
            //- start index >= target index for 'L'
            //- start index <= target index for 'R' 
            if(start_index == n || target_index == n || start[start_index] != target[target_index] 
                || (start[start_index] == 'L' && start_index < target_index)
                || (start[start_index] == 'R' && start_index > target_index)
                )
                break;

            ++start_index, ++target_index;
        }

        return start_index == n && target_index == n;
    }
};
//https://leetcode.com/problems/move-pieces-to-obtain-a-string/
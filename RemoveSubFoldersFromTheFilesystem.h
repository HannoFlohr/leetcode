class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());

        vector<string> result;

        for(string& subfolder : folder) {
            //add to result if
            //- its the first subfolder
            //- folder at back of result is not parent folder of current subfolder
            //- parent matches subfolder for its length, but current subfolder has a longer name (e.g. /a/b and /a/bc)
            if(result.empty() 
                || subfolder.substr(0, result.back().size()) != result.back()
                || subfolder[result.back().size()] != '/'
            )
            result.push_back(subfolder);
        }

        return result;
    }
};
//https://leetcode.com/problems/remove-sub-folders-from-the-filesystem/
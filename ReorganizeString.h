class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> char_count;
        priority_queue<pair<int,char>> q;
        string reorganized = "";

        for(auto& c : s)
            ++char_count[c];

        for(auto& [ch, count] : char_count)
            q.push({count, ch});

        while(q.size() > 1) { 
            auto ch1 = q.top();
            q.pop();
            auto ch2 = q.top();
            q.pop();

            reorganized += ch1.second; 
            reorganized += ch2.second;

            if(--(ch1.first) > 0)
                q.push(ch1);
            if(--(ch2.first) > 0)
                q.push(ch2);
        }

        if(!q.empty()) {
            if(q.top().first > 1)
                return "";
            else
                reorganized += q.top().second;
        }

        return reorganized;
    }
};
//https://leetcode.com/problems/reorganize-string/
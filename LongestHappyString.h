class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string result = "";
        //store chars and their counts in a priority queue
        priority_queue<pair<int,char>> q;
        if(a > 0)
            q.push({a, 'a'});
        if(b > 0)
            q.push({b, 'b'});
        if(c > 0)
            q.push({c, 'c'}); 

        while(!q.empty()) {
            auto [count, ch] = q.top();
            q.pop();

            //if last two chars are the same, take next in queue
            if(result.size() >= 2 && result.back() == ch && result[result.size()-2] == ch) {
                if(q.empty())
                    break;

                auto [count2, ch2] = q.top();
                q.pop();

                result += ch2;
                --count2;

                if(count2 > 0)
                    q.push({count2, ch2});
                q.push({count, ch});
            }
            //else add the char with highest count
            else {
                result += ch;
                --count;
                if(count > 0)
                    q.push({count, ch});
            }
        }
        
        return result;
    }
};
//https://leetcode.com/problems/longest-happy-string/
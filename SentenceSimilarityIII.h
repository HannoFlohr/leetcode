class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        deque<string> q1, q2;
        string s;

        for(char c : sentence1) {
            if(c == ' ') {
                q1.push_back(s); 
                s = "";
            }
            else
                s += c;
        }
        q1.push_back(s);
        s = "";
    
        for(char c : sentence2) {
            if(c == ' ') {
                q2.push_back(s); 
                s = "";
            }
            else
                s += c;
        }
        q2.push_back(s);

        while(q1.size() != 0 && q2.size() && q1.front() == q2.front()) {
            q1.pop_front();
            q2.pop_front();
        }
        while(q1.size() != 0 && q2.size() && q1.back() == q2.back()) {
            q1.pop_back();
            q2.pop_back();
        }

        if(q1.empty() || q2.empty())
            return true;
        return false;
    }
};
//https://leetcode.com/problems/sentence-similarity-iii/
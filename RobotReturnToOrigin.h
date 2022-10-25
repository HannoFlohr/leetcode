class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char,int> freq;
        for(const auto &m : moves)
            freq[m]++;
        
        return freq['U'] == freq['D'] && freq['L'] == freq['R'];
    }
};
//https://leetcode.com/problems/robot-return-to-origin/submissions/

/*

class Solution {
public:
    bool judgeCircle(string moves) {
        short vertical=0, horizontal=0;
        for(const auto &m : moves) 
            switch(m) {
                case 'U' : vertical++; break;
                case 'D' : vertical--; break;
                case 'R' : horizontal++; break;
                case 'L' : horizontal--; break;
            }
    
        return !vertical && !horizontal;
    }
};

*/
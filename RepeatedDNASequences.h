class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.size() < 10) return {};
        
        vector<string> repeated;
        unordered_map<string, int> sequences;
        
        for(int i=0; i<s.size()-9; i++)
            sequences[s.substr(i,10)]++;

        for(auto &seq : sequences)
            if(seq.second > 1)
                repeated.push_back(seq.first);

        return repeated;
    }
};
//https://leetcode.com/problems/repeated-dna-sequences/
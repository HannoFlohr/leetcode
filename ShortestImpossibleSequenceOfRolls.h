class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        int sequence_length = 1;
        unordered_set<int> cur_sequence;
        
        for(auto &r : rolls) {
            cur_sequence.insert(r);

            if(cur_sequence.size() == k) {
                cur_sequence.clear();
                sequence_length++;
            }
        }

        return sequence_length;
    }
};
//https://leetcode.com/problems/shortest-impossible-sequence-of-rolls/

/*
loop through all rolls and create a set for the rolls 
when we have encountered all rolls 1..k a first complete sequence was found in rolls[0..i]
reset the set and continue trying to find further sets in rolls[i+1...] and so on
*/
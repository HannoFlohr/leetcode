class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int start = 0, max_count = 0, count_T = 0, count_F = 0;

        for(int end = 0; end < answerKey.size(); ++end) {
            max_count = max(max_count, (answerKey[end] == 'T' ? ++count_T : ++count_F) );

            if(end-start+1 > max_count+k) {
                answerKey[start] == 'T' ? --count_T : --count_F;
                start++;
            }
        }

        return answerKey.size() - start;
    }
};
//https://leetcode.com/problems/maximize-the-confusion-of-an-exam/
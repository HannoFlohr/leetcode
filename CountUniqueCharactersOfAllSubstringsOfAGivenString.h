class Solution {
public:
    int uniqueLetterString(string s) {
        const int n = s.size();
        
        //stores range to next equal char for each element
        vector<int> left(n,-1), right(n,-1);
        //stores last occurence of each char
        vector<int> last(26,-1);
        
        for(int i=0; i<n; i++) {
            left[i] = i - last[s[i]-'A'];
            last[s[i]-'A'] = i;
        }
        
        last = vector<int>(26,n);
        
        for(int i=n-1; i>=0; i--) {
            right[i] = last[s[i]-'A'] - i;
            last[s[i]-'A'] = i;
        }

        //sum up contribution
        int contribution = 0;
        for(int i=0; i<n; i++)
            contribution += (left[i] * right[i]);
        
        return contribution;
    }
};
//https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/

/* similar approach to 'SumOfSubarrayMinimums'

for each s[i] find the range to the next equal char to left and right
the contribution can than be summed up as left[i] * right[i] for all i 

*/

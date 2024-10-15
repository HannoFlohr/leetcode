class Solution {
public:
    string nearestPalindromic(string n) {
        //single digit numbers
        if(n.size() == 1) {
            return to_string(stoi(n)-1);
        }
            
        const int digits = n.size();

        //make list of candidates
        vector<long> candidates;
        //case: closest palindrome has one digit less
        candidates.push_back(pow(10,digits-1)-1);
        //case: closest palindrome has one digit more
        candidates.push_back(pow(10,digits)+1); 
        /*  
            case: closest palindrome has same digits
            three possible subcases
            - middle stays the same
            - middle increases by one
            - middle decreases by one
            the parts pre and post the middle need to mirror
        */
        int mid = (digits+1)/2;
        long pre = stol(n.substr(0,mid));
        vector<long> prefixes = {pre, pre+1, pre-1};
        for(long pre : prefixes) {
            string post = to_string(pre);
            if(digits%2 != 0)
                post.pop_back();
            reverse(post.begin(), post.end());
            string candidate = to_string(pre) + post;
            candidates.push_back(stol(candidate));
        }

        //find closest candidate
        long min_difference = LONG_MAX, closest, number = stol(n);
        for(long candidate : candidates) {
            if(candidate != number && abs(candidate - number) < min_difference) {
                min_difference = abs(candidate - number);
                closest = candidate;
            }
            else if(abs(candidate - number) == min_difference && candidate < closest) {
                closest = candidate;
            }
        }

        return to_string(closest);
    }
};
//https://leetcode.com/problems/find-the-closest-palindrome/
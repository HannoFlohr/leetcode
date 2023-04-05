class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long result = 0, count1, count2;
        unordered_set<string> postfix[26];
        
        for(const auto& idea : ideas)
            postfix[idea[0]-'a'].insert(idea.substr(1));

        for(int i=0; i<26; i++) {
            for(int j=i+1; j<26; j++) {
                count1 = 0L, count2 = 0L;

                for(const auto& s : postfix[i])
                    if(postfix[j].find(s) == postfix[j].end())
                        count1++;
                for(const auto& s : postfix[j]) 
                    if(postfix[i].find(s) == postfix[i].end())
                        count2++;

                result += count1 * count2;
            }
        }

        return result * 2;
    }
};
//https://leetcode.com/problems/naming-a-company/

/*
for each idea[i]: idea = first letter + postfix 
-> group ideas in sets by first letters

two ideas i and j form a valid result if they dont share a prefix
for each i and j count non-common prefix and sum up for the result 
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> words (wordList.begin(), wordList.end());
        if(words.find(endWord) == words.end())
            return 0;

        queue<string> q;
        set<string> visited;
        q.push(beginWord);
        visited.insert(beginWord);
        
        string word, try_next;
        int qsize, transformations = 1;

        while(!q.empty()) {
            qsize = q.size();

            for(size_t i=0; i<qsize; i++) {
                word = q.front();
                q.pop();

                if(word == endWord) return transformations;

                for(size_t j=0; j<word.length(); j++) {
                    try_next = word;
                    for(char c='a'; c<='z'; c++) {
                        try_next[j] = c;

                        if(words.find(try_next) != words.end() && visited.find(try_next) == visited.end()) {
                            q.push(try_next);
                            visited.insert(try_next);
                        }
                    }
                }
            }
            transformations++;
        }

        return 0;
    }
};
//https://leetcode.com/problems/word-ladder/
class Solution {
private:
    //memory for words that are checked if they are a palindrome
    unordered_map<string,bool> checked_for_palindromic_before;

    //returns true if string word is a palindrome
    bool isPalindrome(string& word) {
        //use memory if possible
        if(checked_for_palindromic_before.contains(word)) {
            return checked_for_palindromic_before[word];
        }
        if(word.size() == 0) {
            return checked_for_palindromic_before[word] = true;
        }

        int front = 0, back = word.size()-1;
        while(front < back) {
            if(word[front] != word[back]) {
                return checked_for_palindromic_before[word] = false;
            }
            ++front;
            --back;
        }

        return checked_for_palindromic_before[word] = true;
    }

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> palindrome_pairs;
        unordered_map<string,int> reversed;

        //compute and store reverse of all words
        for(int i = 0; i < words.size(); ++i) {
            string word = words[i];
            reverse(word.begin(), word.end());
            reversed[word] = i;
        } 

        //if the empty string is part of words, all words that are a palindrome themselves 
        //form a palindrome pair with the empty string
        if(reversed.contains("")) {
            for(int i = 0; i < words.size(); ++i) {
                if(i == reversed[""]) {
                    continue;
                }
                if(isPalindrome(words[i])) {
                    palindrome_pairs.push_back({i, reversed[""]});
                }
            }
        }

        //check all words
        for(int i = 0; i < words.size(); ++i) {
            string left = "", right = words[i];
        
            //switch letters from right to left to try to find palindrome pairs
            for(int j = 0; j < words[i].size(); ++j) {
                left.push_back(*right.begin());
                right.erase(right.begin());

                if(reversed.contains(left) && reversed[left] != i && isPalindrome(right)) {
                    palindrome_pairs.push_back({i, reversed[left]});
                }
                if(reversed.contains(right) && reversed[right] != i && isPalindrome(left)) {
                    palindrome_pairs.push_back({reversed[right], i});
                }
            }
        }

        return palindrome_pairs;
    }
};
//https://leetcode.com/problems/palindrome-pairs/
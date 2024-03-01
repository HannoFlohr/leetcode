class Solution {
private:
    bool isvowel(char ch) { 
        return (ch == 'a') || (ch == 'e') || (ch == 'i') || (ch == 'o') || (ch == 'u') || 
                (ch == 'A') || (ch == 'E') || (ch == 'I') || (ch == 'O') || (ch == 'U'); 
    }
public:
    string toGoatLatin(string sentence) {
        istringstream ss (sentence);
        string word, result = "";
        int word_index = 1;

        while(ss >> word) {
            if(!isvowel(word[0])) {
                word = word.substr(1, word.size()-1) + word[0];
            }
            word += "ma" + string(word_index++, 'a');

            if(result != "") {
                result += " ";
            }
            result += word;
        }    

        return result;
    }
};
//https://leetcode.com/problems/goat-latin/
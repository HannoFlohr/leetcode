class WordDictionary {
private:
    bool is_end;
    WordDictionary* children [26]{}; 

    bool search(WordDictionary* node, const string& word, int pos) {
        if(pos == word.size()) return node->is_end;

        if(word[pos] != '.') {
            node = node->children[word[pos]-'a'];
            return node ? search(node, word, pos+1) : false;
        }

        for(int i=0; i<26; i++) 
            if(node->children[i] && search(node->children[i], word, pos+1))
                return true;

        return false;
    }

public:
    WordDictionary() : is_end(false) {}
    
    void addWord(const string& word) {
        WordDictionary *current = this;

        for(auto &c : word){
            if(current->children[c-'a'] == nullptr) 
                current->children[c-'a'] = new WordDictionary();
            current = current->children[c-'a'];
        }
        current->is_end = true;
    }
    
    bool search(const string& word) {
        WordDictionary* current = this;
        return search(current, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
 
 //https://leetcode.com/problems/design-add-and-search-words-data-structure/
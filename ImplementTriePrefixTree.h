class Trie {
private:
	bool is_leaf;
	std::map<char,Trie*> children;

public:
    Trie() {
        this->is_leaf = false;
    }
    
    void insert(string word) {
		Trie *current_node = this, *child_node; 

		for (int i = 0; i < word.length(); i++) {
			child_node = current_node->children[word[i]];
			if (child_node == nullptr) {
				child_node = new Trie();
				current_node->children[word[i]] = child_node; 
			}
			current_node = child_node;
		}

		current_node->is_leaf = true;
    }
    
    bool search(string word) {
		Trie* current_node = this;

		for (int i = 0; i < word.length(); i++) {
			current_node = current_node->children[word[i]];
			if (current_node == nullptr)
				return false;
		}

		return current_node->is_leaf;
    }
    
    bool startsWith(string prefix) {
        if (this == nullptr) return false;

		Trie* current_node = this;

		for (int i = 0; i < prefix.length(); i++) {
			current_node = current_node->children[prefix[i]];
			if (current_node == nullptr)
				return false;
		}

		return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
 
 //https://leetcode.com/problems/implement-trie-prefix-tree/
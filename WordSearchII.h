class TrieNode {
public:
    bool is_end_node;
    vector<TrieNode*> children;
    TrieNode() {
        is_end_node = false;
        children = vector<TrieNode*>(26, NULL);
    }
};

class Trie{
private: 
    TrieNode* root;
public:
    Trie(const vector<string> &words) {
        root = new TrieNode();
        for(auto &word : words)
            addWord(word);
    }
    
    void addWord(const string &word) {
        TrieNode* cur = root;
        for(auto &c : word) {
            int index = c - 'a';
            if(cur->children[index] == NULL)
                cur->children[index] = new TrieNode();
            cur = cur->children[index];
        }
        cur->is_end_node = true;
    }
    
    TrieNode* getRoot() {
        return root;
    }
};

class Solution {
private:
    int m, n;
    vector<string> results;
    
    bool inBounds(const int &i, const int &j) {
        return i>=0 && i<m && j>=0 && j<n;
    } 
    
    void find(vector<vector<char>>& board, int i, int j, TrieNode* root, string word) { 
        //check if in bounds and if already visited
        if(!inBounds(i,j) || board[i][j] == ' ') return;
        
        if(root->children[ board[i][j] - 'a' ] != NULL) {
            word += board[i][j];
            root = root->children[ board[i][j] - 'a' ];
            
            //found the last letter of the word, insert in results
            if(root->is_end_node) {
                results.push_back(word);
                root->is_end_node = false;
            }
        
            //mark cell as visited
            char c = board[i][j];
            board[i][j] = ' ';
            
            //search in all four possible directions
            find(board, i-1,  j,    root,   word);
            find(board, i+1,  j,    root,   word);
            find(board, i,    j-1,  root,   word);
            find(board, i,    j+1,  root,   word);
            
            //backtrack marking of cell to not visited
            board[i][j] = c;
        }
    }
    
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(), n = board[0].size();
        
        Trie* trie = new Trie(words);
        TrieNode* root = trie->getRoot();
        
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                find(board, i, j, root, "");
        
        return results;
    }
};
//https://leetcode.com/problems/word-search-ii/
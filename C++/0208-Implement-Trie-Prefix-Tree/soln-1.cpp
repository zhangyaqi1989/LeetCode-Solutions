struct TrieNode {
    bool is_word;
    vector<TrieNode *> children;
    
    TrieNode(): is_word(false) {
        children.resize(26);
    }
    // TrieNode(const TrieNode & other) = delete;
    // TrieNode & operator=(const TrieNode & other) = delete;
    ~TrieNode() {
        for(int i = 0; i < 26; ++i) {
            if (children[i] != nullptr) {
                delete children[i];
                children[i] = nullptr;
            }
        }
    }
};
class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
       root = TrieNode(); 
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode * cur = & root;
        for(char ch : word) {
            if (cur->children[ch - 'a'] == nullptr) cur->children[ch - 'a'] = new TrieNode();
            cur = cur->children[ch - 'a'];
        }
        cur->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode * cur = & root;
        for(char ch : word) {
            if (cur->children[ch - 'a'] == nullptr) return false;
            cur = cur->children[ch - 'a'];
        }
        return cur->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode * cur = & root;
        for(char ch : prefix) {
            if (cur->children[ch - 'a'] == nullptr) return false;
            cur = cur->children[ch - 'a'];
        }
        return true;
    }
    
private:
    TrieNode root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

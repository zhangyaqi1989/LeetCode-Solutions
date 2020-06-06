struct TrieNode {
    bool is_word;
    vector<TrieNode *> children;
    TrieNode(): is_word(false) {
        children.assign(26, nullptr);
    }
    ~TrieNode() {
        for(int i = 0; i < 26; ++i) {
            if(children[i] != nullptr) {
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
        TrieNode root_ = TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode * cur = & root_;
        for(char ch : word) {
            if (cur->children[ch - 'a'] == nullptr) {
                cur->children[ch - 'a'] = new TrieNode();
            }
            cur = cur->children[ch - 'a'];
        }
        cur->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode * cur = & root_;
        for(char ch : word) {
            cur = cur->children[ch - 'a'];
            if(cur == nullptr) return false;
        }
        return cur->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode * cur = & root_;
        for(char ch : prefix) {
            cur = cur->children[ch - 'a'];
            if(cur == nullptr) return false;
        }
        return true;
    }
private:
    TrieNode root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class TrieNode{
    public:
    bool is_word;
    map<char, TrieNode*> children;
    
    TrieNode() {
        is_word = false;
    }
};
class Trie {
    TrieNode * root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode * cur = root;
        for(char ch : word) {
            auto it = cur->children.find(ch);
            if (it == cur->children.end()) {
                cur->children[ch] = new TrieNode();
                cur = cur->children[ch];
            } else {
                cur = it->second;
            }
        }
        cur->is_word = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode * cur = root;
        for(char ch : word) {
            auto it = cur->children.find(ch);
            if (it == cur->children.end()) return false;
            else cur = it->second;
        }
        return cur->is_word;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode * cur = root;
        for(char ch : prefix) {
            auto it = cur->children.find(ch);
            if (it == cur->children.end()) return false;
            else cur = it->second;
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

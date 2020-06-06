class TrieNode {
public:
    bool is_word;
    TrieNode * children[26];
    TrieNode(): is_word(false) {
        memset(children, 0, sizeof children);
    }
};

class StreamChecker {
    TrieNode * root;
    string q;
public:
    StreamChecker(vector<string>& words) {
        q = "";
        root = new TrieNode();
        for(string word : words) {
            TrieNode * cur = root;
            int m = word.length();
            for(int i = m - 1; i >= 0; --i) {
                if (cur->children[word[i] - 'a'] == nullptr) {
                    cur->children[word[i] - 'a'] = new TrieNode();
                }
                cur = cur->children[word[i] - 'a'];
            }
            cur->is_word = true;
        }
    }
    
    bool query(char letter) {
        q += letter;
        int m = q.length();
        TrieNode * cur = root;
        for(int i = m - 1; i >= 0; --i) {
            cur = cur->children[q[i] - 'a'];
            if (cur == nullptr) return false;
            if (cur->is_word) return true;
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

class TrieNode {
public:
    bool is_word;
    unordered_map<char, TrieNode*> children;
    TrieNode (): is_word(false) {};
};

class StreamChecker {
    TrieNode root;
    string q;
public:
    StreamChecker(vector<string>& words) {
        for(string word : words) {
            int m = word.length();
            TrieNode * ptr = & root;
            for(int i = m - 1; i >= 0; --i) {
                if (ptr->children.find(word[i]) == ptr->children.end()) {
                    ptr->children[word[i]] = new TrieNode();
                }
                ptr = ptr->children[word[i]];
            }
            ptr->is_word = true;
        }
        q = "";
    }
    
    bool query(char letter) {
        q += letter;
        TrieNode * ptr = & root;
        int m = q.length();
        for(int i = m - 1; i >= 0; --i) {
            auto it = ptr->children.find(q[i]);
            if (it == ptr->children.end()) {
                return false;
            } else {
                ptr = it->second;
                if (ptr->is_word) return true;
            }
        }
        return false;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

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

class StreamChecker {
public:
    StreamChecker(vector<string>& words) {
        root = TrieNode();
        for(const auto & word : words) {
            TrieNode * cur = & root;
            for(auto it = word.crbegin(); it != word.crend(); ++it) {
                if(cur->children[*it - 'a'] == nullptr) {
                    cur->children[*it - 'a'] = new TrieNode();
                }
                cur = cur->children[*it - 'a'];
            }
            cur->is_word = true;
        }
    }
    
    bool query(char letter) {
        stream.push_back(letter);
        TrieNode * cur = & root;
        for(auto it = stream.crbegin(); it != stream.crend(); ++it) {
            if(cur->children[*it - 'a'] == nullptr) return false;
            cur = cur->children[*it - 'a'];
            if (cur->is_word) return true;
        }
        return false;
    }
    
private:
    TrieNode root;
    deque<char> stream;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

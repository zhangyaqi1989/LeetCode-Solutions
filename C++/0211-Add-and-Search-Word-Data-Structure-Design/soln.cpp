class WordDictionary {
    map<int, set<string>> words;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        words[word.length()].insert(word);
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        int n = word.length();
        if (word.find('.') == string::npos) {
            return words[n].count(word);
        }
        for(string item : words[n]) {
            bool valid = true;
            for(int i = 0; i < n; ++i) {
                if (word[i] != '.' && word[i] != item[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

class MagicDictionary {
    set<string> words;
    map<string, int> m;
public:
    /** Initialize your data structure here. */
    MagicDictionary() {
        
    }
    
    /** Build a dictionary through a list of words */
    void buildDict(vector<string> dict) {
        for(string word : dict) {
            words.insert(word);
            int n = word.length();
            for(int i = 0; i < n; ++i) {
                string temp = word.substr(0, i) + "#" + word.substr(i + 1);
                ++m[temp];
            }
        }
    }
    
    /** Returns if there is any word in the trie that equals to the given word after modifying exactly one character */
    bool search(string word) {
        int cnt = 0;
        if (words.find(word) != words.end()) cnt = 1;
        int n = word.size();
        for(int i = 0; i < n; ++i) {
            string temp = word.substr(0, i) + "#" + word.substr(i + 1);
            if (m[temp] > cnt)
                return true;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * bool param_2 = obj.search(word);
 */

class ValidWordAbbr {
    unordered_map<string, set<string>> abbrs;
public:
    ValidWordAbbr(vector<string> dictionary) {
        abbrs.clear();
        for(string word : dictionary) abbrs[computeAbbr(word)].insert(word);
    }
    
    string computeAbbr(string word) {
        if(word.length() <= 2) return word;
        int n = word.length();
        return word.substr(0, 1) + to_string(n - 2) + word.substr(n - 1);
    }
    
    bool isUnique(string word) {
        auto it = abbrs.find(computeAbbr(word));
        return it == abbrs.end() or ((it->second).size() == 1 && (*(it->second.begin())) == word);
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */

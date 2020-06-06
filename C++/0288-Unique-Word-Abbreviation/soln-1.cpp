class ValidWordAbbr {
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for(const auto & word : dictionary) {
            string abb = word.length() <= 2 ? word : word.substr(0, 1) + to_string(word.length() - 2) + word.back();
            abbs_[abb].insert(word);
        }
    }
    
    bool isUnique(string word) {
        string abb = word.length() <= 2 ? word : word.substr(0, 1) + to_string(word.length() - 2) + word.back();
        auto it = abbs_.find(abb);
        return it == abbs_.end() || (it->second.size() == 1 && *it->second.begin() == word);
    }
    
private:
    unordered_map<string, unordered_set<string>> abbs_; 
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */

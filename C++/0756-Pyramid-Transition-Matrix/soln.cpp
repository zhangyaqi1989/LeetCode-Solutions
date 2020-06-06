class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        map<string, set<string>> m;
        for(string allow : allowed){
            m[allow.substr(0, 2)].insert(allow.substr(2));
        }
        return helper(bottom, m);
    }
    
    bool helper(string bottom, map<string, set<string>> & m) {
        if (bottom.length() == 1) return true;
        else {
            int n = bottom.length();
            vector<string> levels = {""};
            for(int i = 0; i < n - 1; ++i) {
                string base = bottom.substr(i, 2);
                vector<string> temp;
                auto it = m.find(base);
                if (it == m.end()) {
                    return false;
                } else {
                    for(string level : levels) {
                        for(string cand : it->second) {
                            temp.push_back(level + cand);
                        }
                    }
                }
                swap(levels, temp);
            }
            for(string level : levels) {
                if (helper(level, m)) return true;
            }
            return false;
        }
    }
};

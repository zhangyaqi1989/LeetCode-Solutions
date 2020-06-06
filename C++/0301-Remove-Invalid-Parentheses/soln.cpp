class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> level;
        level.insert(s);
        while(true) {
            for(auto item : level) {
                if (is_valid(item)) ans.push_back(item);
            }
            if (!ans.empty()) return ans;
            unordered_set<string> temp;
            for(auto item : level) {
                for(int i = 0; i < item.size(); ++i) {
                    temp.insert(item.substr(0, i) + item.substr(i + 1));
                }
            }
            swap(level, temp);
        }
        return ans;
    }
    
    bool is_valid(string s) {
        int cnt = 0;
        for(char ch : s) {
            if (ch == '(') ++cnt;
            else if (ch == ')') {
                --cnt;
                if (cnt < 0) return false;
            }
        }
        return cnt == 0;
    }
};

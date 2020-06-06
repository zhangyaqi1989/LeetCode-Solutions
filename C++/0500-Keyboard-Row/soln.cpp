class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        vector<string> rows = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        unordered_map<char, int> key;
        int row = 0;
        for(auto string : rows) {
            ++row;
            for(auto ch : string) {
                key[ch] = row;
            }
        }
        unordered_set<int> s;
        for(auto string : words) {
            s.clear();
            bool flag = true;
            for(auto ch : string) {
                s.insert(key[tolower(ch)]);
                if (s.size() > 1) {
                    flag = false;
                    break;
                }
            }
            if (flag) ans.push_back(string);
        }
        return ans;
    }
};
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> ans;
        for(auto s : A) ans.insert(encode(s));
        return ans.size();
    }
    
    string encode(string s) {
        int n = s.length();
        string evens = "", odds = "";
        for(int i = 0; i < n; i += 2) evens += s[i];
        for(int i = 1; i < n; i += 2) odds += s[i];
        sort(evens.begin(), evens.end());
        sort(odds.begin(), odds.end());
        return evens + odds;
    }
};

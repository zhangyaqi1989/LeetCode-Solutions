class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        map<string, vector<string>> m;
        for(string & str : strings) {
            m[normalize(str)].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto & p : m) ans.push_back(p.second);
        return ans;
    }
    
    string normalize(string & s) {
        int shift = s[0] - 'a';
        string ans = "";
        for(char & ch : s) {
            ans += ch - shift < 'a' ? ch - shift + 26 : ch - shift; 
        }
        return ans;
    }
};

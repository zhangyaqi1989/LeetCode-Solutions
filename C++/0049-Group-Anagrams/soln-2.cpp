class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        for(string & s : strs) {
            string code(s);
            sort(code.begin(), code.end());
            m[code].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto & p : m) {
            ans.push_back(p.second);
        }
        return ans;
    }
};

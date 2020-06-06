class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for(const string & str : strs) {
            string code(str);
            sort(code.begin(), code.end());
            groups[code].push_back(str);
        }
        vector<vector<string>> ans;
        ans.reserve(groups.size());
        for(const auto & p : groups) {
            ans.push_back(p.second);
        }
        return ans;
    }
};

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen, repeated;
        int n = s.length();
        for(int i = 0; i < n - 9; ++i) {
            string sub = s.substr(i, 10);
            if (seen.find(sub) != seen.end()) {
                repeated.insert(sub);
            } else {
                seen.insert(sub);
            }
        }
        vector<string> ans;
        for(auto sub : repeated) ans.push_back(sub);
        return ans;
    }
};

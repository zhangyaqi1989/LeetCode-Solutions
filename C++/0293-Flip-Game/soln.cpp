class Solution {
public:
    vector<string> generatePossibleNextMoves(string s) {
        int i = 0, n = s.length();
        vector<string> ans;
        while(i < n) {
            auto j = s.find("++", i);
            if (j == string::npos) return ans;
            else {
                ans.push_back(s.substr(0, j) + "--" + s.substr(j + 2));
                i = j + 1;
            }
        }
        return ans;
    }
};

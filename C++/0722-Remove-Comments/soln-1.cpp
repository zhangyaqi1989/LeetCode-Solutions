class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        bool inblock = false;
        string code;
        for(const string & line : source) {
            int n = line.length();
            if (!inblock) code.clear();
            for(int i = 0; i < n; ++i) {
                if (!inblock && i + 1 < n && line.substr(i, 2) == "//") {
                    break;
                }
                if (!inblock && i + 1 < n && line.substr(i, 2) == "/*") {
                    inblock = true;
                    ++i;
                    continue;
                }
                if (inblock && i + 1 < n && line.substr(i, 2) == "*/") {
                    inblock = false;
                    ++i;
                    continue;
                }
                if (!inblock) code += line[i];
            }
            if (!inblock && !code.empty()) ans.push_back(code);
        }
        return ans;
    }
};

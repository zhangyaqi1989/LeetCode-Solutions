class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        string s = "";
        for (auto line : source) s += line + '\n';
        int i = 0;
        string left = "";
        int n = s.length();
        while (i < n) {
            if (i < n - 1 && s[i] == '/' && s[i + 1] == '*') {
                i = i + 2;
                while (i < n - 1 && (s[i] != '*' || s[i + 1] != '/')) ++i;
                i = i + 2;
            } else if (i < n - 1 && s[i] == '/' && s[i + 1] == '/') {
                i = i + 2;
                while (i < n && s[i] != '\n') ++i;
            } else {
                left += s[i++];
            }
        }
        vector<string> ans;
        string line;
        stringstream iss(left);
        while (getline(iss, line)) {
            if (!line.empty()) ans.push_back(line);
        }
        return ans; 
    }
};

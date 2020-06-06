class Solution {
public:
    string simplifyPath(string path) {
        string temp;
        vector<string> stk;
        istringstream iss(path);
        while (getline(iss, temp, '/')) {
            if (temp == "" || temp == ".") continue;
            else if (temp == "..") {
                if (!stk.empty()) stk.pop_back();
            } else {
                stk.push_back(temp);
            }
        }
        string ans = "/";
        int n = stk.size();
        for(int i = 0; i < n; ++i) {
            ans += (stk[i] + (i < n - 1 ? "/" : ""));
        }
        return ans;
    }
};

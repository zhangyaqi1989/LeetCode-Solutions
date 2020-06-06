class Solution {
public:
    vector<string> permute(string S) {
        vector<string> ans = {""};
        int i = 0, n = S.length();
        while (i < n) {
            vector<string> temp;
            auto j = S.find('{', i);
            if (j == string::npos) {
                string add = S.substr(i);
                for(string item : ans) {
                    temp.push_back(item + add);
                }
                i = n;
            } else {
                auto jj = S.find('}', j + 1);
                string add = S.substr(i, j - i);
                for(string & item : ans) item += add;
                string str = S.substr(j + 1, jj - j - 1);
                for(int ii = 0; ii < str.length(); ii += 2) {
                    string token = str.substr(ii, 1);
                    for(string item : ans) temp.push_back(item + token);
                }
                i = jj + 1;
            }
            swap(temp, ans);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

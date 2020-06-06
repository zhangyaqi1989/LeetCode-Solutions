class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;
        for(string path : folder) {
            if(ans.empty() || !startswith(path + "/", ans.back() + "/")) {
                ans.push_back(path);
            }
        }
        return ans;
    }

private:
    bool startswith(const string & text, const string & prefix) {
        return prefix.length() <= text.length() && prefix == text.substr(0, (int) prefix.length());
    }
};

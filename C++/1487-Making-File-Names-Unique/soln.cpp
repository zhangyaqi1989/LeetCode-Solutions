class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> nxt;
        unordered_set<string> seen;
        vector<string> ans;
        for(const string & name : names) {
            if(!seen.count(name)) {
                ans.push_back(name);
            } else {
                auto it = nxt.find(name);
                int suffix = (it == nxt.end() ? 1 : it->second);
                while(seen.count(name + "(" + to_string(suffix) + ")")) {
                    ++suffix;
                }
                ans.push_back(name + "(" + to_string(suffix) + ")");
                nxt[name] = suffix + 1;
            }
            seen.insert(ans.back());
        }
        return ans;
    }
};

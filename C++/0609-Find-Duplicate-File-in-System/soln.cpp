class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> m;
        for(string & path : paths) {
            istringstream iss(path);
            string file;
            string parent;
            iss >> parent;
            while (iss >> file) {
                int idx = file.find('(');
                string name = file.substr(0, idx);
                string content = file.substr(idx + 1, file.length() - 2 - idx);
                m[content].push_back(parent + "/" + name);
            }
        }
        vector<vector<string>> ans;
        for(auto & p : m) {
            if (p.second.size() > 1) ans.push_back(p.second);
        }
        return ans;
    }
};

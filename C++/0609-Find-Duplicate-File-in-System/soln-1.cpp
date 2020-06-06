class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string, vector<string>> dict;
        for (auto & path : paths) {
            istringstream iss(path);
            string dir;
            iss >> dir;
            string file;
            while (iss >> file) {
                int idx = file.rfind("(");
                string content = file.substr(idx + 1, file.length() - 1 - idx - 1);
                string name = file.substr(0, idx);
                dict[content].push_back(dir + '/' + name);
            }
        }
        vector<vector<string>> ans;
        for(auto & p : dict) {
            if (p.second.size() >= 2)
                ans.push_back(p.second);
        }
        return ans;
    }
};

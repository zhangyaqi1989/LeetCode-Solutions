struct TrieNode {
    map<string, TrieNode *> children;
    bool is_word;
    TrieNode(): is_word(false){}
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(), folder.end(), [](const string & a, const string & b) {return a.length() < b.length();});
        TrieNode root = TrieNode();
        for(string path : folder) {
            TrieNode * cur = & root;
            int i = 1;
            int n = path.length();
            bool is_in = false;
            while(i < n) {
                auto j = path.find('/', i);
                if (j == string::npos) {
                    j = n;
                }
                string name = path.substr(i, j - i);
                i = j + 1;
                auto it = cur->children.find(name);
                if(it == cur->children.end()) {
                    cur->children[name] = new TrieNode();
                    cur = cur->children[name];
                } else {
                    cur = it->second;
                }
                if (cur->is_word) {
                    is_in = true;
                    break;
                }
            }
            if(!is_in) {
                cur->is_word = true;
                ans.push_back(path);
            }
        }
        return ans;
    }
};

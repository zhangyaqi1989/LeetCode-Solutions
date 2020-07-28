struct TrieNode {
    int value;
    map<string, TrieNode*> children;
    TrieNode():value(-1) {};
};

class FileSystem {
public:
    FileSystem() {
        root_ = TrieNode();
    }
    
    bool createPath(string path, int value) {
        TrieNode * cur = & root_;
        vector<string> dirs = ToDirs(path);
        int n = dirs.size();
        for(int i = 0; i < n - 1; ++i) {
            auto it = cur->children.find(dirs[i]);
            if(it == cur->children.end()) {
                return false;
            }
            cur = it->second;
        }
        auto it = cur->children.find(dirs.back());
        if(it != cur->children.end()) return false;
        cur->children[dirs.back()] = new TrieNode();
        cur->children[dirs.back()]->value = value;
        return true;
    }
    
    int get(string path) {
        TrieNode * cur = & root_;
        vector<string> dirs = ToDirs(path);
        int n = dirs.size();
        for(int i = 0; i < n; ++i) {
            auto it = cur->children.find(dirs[i]);
            if(it == cur->children.end()) {
                return -1;
            }
            cur = it->second;
        }
        return cur->value;
    }
    

private:
    
    vector<string> ToDirs(string path) {
        vector<string> dirs;
        const int kN = path.length();
        for(int i = 1; i < kN;++i) {
            string dir;
            while(i < kN && path[i] != '/') {
                dir += path[i++];
            }
            dirs.push_back(dir);
        }
        return dirs;
    }
    
    TrieNode root_;
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */

class Solution {
public:
    string crackSafe(int n, int k) {
        // k^n
        string passwd = string(n, '0');
        unordered_set<string> visited = {passwd};
        int total = pow(k, n);
        dfs(visited, passwd, total, k, n);
        return passwd;
    }
    
private:
    bool dfs(unordered_set<string> & visited, string & passwd, int total, int k, int n) {
        if (visited.size() == total) return true;
        string suffix = passwd.substr(passwd.size() - n + 1);
        for(char ch = '0'; ch < '0' + k; ++ch) {
            string nxt = suffix + ch;
            if (!visited.count(nxt)) {
                passwd += ch;
                visited.insert(nxt);
                if (dfs(visited, passwd, total, k, n)) return true;
                else {
                    passwd.pop_back();
                    visited.erase(nxt);
                }
            }
        }
        return false;
    }
};

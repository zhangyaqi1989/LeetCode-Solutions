struct TrieNode {
    bool is_word;
    vector<TrieNode *> children;
    
    TrieNode(): is_word(false), children(26, nullptr) {}
    ~TrieNode() {
        const int n = children.size();
        for(int i = 0; i < n; ++i) {
            if (children[i] != nullptr) {
                delete children[i];
                children[i] = nullptr;
            }
        }
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        if (board.empty() || board[0].empty()) return ans;
        TrieNode root = TrieNode();
        for(const string & word : words) {
            TrieNode * cur = & root;
            for(char ch : word) {
                if (cur->children[ch - 'a'] == nullptr) cur->children[ch - 'a'] = new TrieNode();
                cur = cur->children[ch - 'a'];
            }
            cur->is_word = true;
        }
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                TrieNode * cur = & root;
                string path;
                dfs(i, j, board, ans, cur, path);
            }
        }
        return ans;
    }
    
private:
    void dfs(int i, int j, vector<vector<char>> & board, vector<string> & ans, TrieNode * cur, string & path) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] == '#') return;
        char ch = board[i][j];
        board[i][j] = '#';
        if (cur->children[ch - 'a'] != nullptr) {
            cur = cur->children[ch - 'a'];
            path += ch;
            if (cur->is_word) {
                ans.push_back(path);
                cur->is_word = false;
            }
            dfs(i - 1, j, board, ans, cur, path);
            dfs(i + 1, j, board, ans, cur, path);
            dfs(i, j - 1, board, ans, cur, path);
            dfs(i, j + 1, board, ans, cur, path);
            path.pop_back();
        }
        board[i][j] = ch;
    }
};

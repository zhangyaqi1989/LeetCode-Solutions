class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> Q(n, 0);
        queen(ans, Q, 0);
        return ans;
    }
    
    void queen(vector<vector<string>> & ans, vector<int> & Q, int idx) {
        int n = Q.size();
        if (idx == n) {
            ans.push_back(encode(Q));
        } else {
            for(int i = 0; i < n; ++i) {
                bool flag = true;
                for(int j = 0; j < idx; ++j) {
                    if (Q[j] == i || idx + i == j + Q[j] || idx - i == j - Q[j]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    Q[idx] = i;
                    queen(ans, Q, idx + 1);
                }
            }
        }
        
    }
    
    vector<string> encode(vector<int> Q) {
        int n = Q.size();
        vector<string> ans;
        for(int i = 0; i < n; ++i) {
            vector<char> v(n, '.');
            v[Q[i]] = 'Q';
            string s(v.begin(), v.end());
            ans.push_back(s);
        }
        return ans;
    }
};

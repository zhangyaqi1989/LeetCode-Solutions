class Solution {
public:
    int totalNQueens(int n) {
        int cnt = 0;
        vector<int> Q(n, 0);
        queen(Q, 0, cnt);
        return cnt;
    }
    
    void queen(vector<int> & Q, int idx, int & cnt) {
        int n = Q.size();
        if (idx == n) cnt++;
        else {
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
                    queen(Q, idx + 1, cnt);
                }
            }
        }
    }
};

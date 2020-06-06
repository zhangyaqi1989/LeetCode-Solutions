class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        string ans(dominoes);
        vector<int> leftRs;
        int last_R = -1;
        for(int i = 0; i < n; ++i) {
            char d = dominoes[i];
            if (d == 'R') {
                last_R = 0;
                ans[i] = 'R';
            } else if (d == 'L') {
                last_R = -1;
                ans[i] = 'L';
            } else {
                if (last_R != -1) {
                    ++last_R;
                    ans[i] = 'R';
                } else {
                    ans[i] = '.';
                }
            }
            leftRs.push_back(last_R);
        }
        int right_L = -1;
        for(int i = n - 1; i >= 0; --i) {
            char d = dominoes[i];
            if (d == 'L') {
                right_L = 0;
            } else if (d == 'R') {
                right_L = -1;
            } else {
                if (right_L != -1) {
                    right_L += 1;
                    if (leftRs[i] == -1 || right_L < leftRs[i]) {
                        ans[i] = 'L';
                    }
                    if (right_L == leftRs[i]) {
                        ans[i] = '.';
                    }
                }
            }
        }
        return ans;
    }
};

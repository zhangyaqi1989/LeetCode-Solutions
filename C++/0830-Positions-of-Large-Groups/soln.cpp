class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        S += 'A';
        vector<vector<int>> ans;
        int i = 0, cnt = 0;
        for(int j = 0; j < S.size(); ++j) {
            if (S[j] != S[i]) {
                if(cnt >= 3)
                    ans.push_back({i, j - 1});
                i = j;
                cnt = 1;
            } else
                cnt++;
        }
        return ans;
    }
};
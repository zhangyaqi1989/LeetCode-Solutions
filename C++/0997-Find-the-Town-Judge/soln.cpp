class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        // a trust b
        int out_degrees[N + 1] = {0};
        int in_degrees[N + 1] = {1};
        for(auto & row : trust) {
            int a = row[0], b = row[1];
            out_degrees[a]++;
            in_degrees[b]++;
        }
        for(int i = 1; i <= N; ++i) {
            if(out_degrees[i] == 0 && in_degrees[i] == N - 1)
                return i;
        }
        return -1;
    }
};

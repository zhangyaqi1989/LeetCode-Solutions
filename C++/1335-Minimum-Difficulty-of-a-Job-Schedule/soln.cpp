int pres[305];
int memo[305][12];
const int kInf = 1e9 + 9;

class Solution {
public:
    int minDifficulty(vector<int>& jobs, int d) {
        memset(memo, -1, sizeof(memo));
        memset(pres, 0, sizeof(pres));
        const int kN = jobs.size();
        for(int i = 0; i < kN; ++i) {
            pres[i + 1] = pres[i] + jobs[i];
        }
        int ans = Helper(jobs, 0, d);
        return ans == kInf ? -1 : ans;
    }
    
private:
    int Helper(const vector<int> & jobs, int idx, int d) {
        const int kN = jobs.size();
        if (kN - idx < d) return kInf;
        if (kN - idx == d) return pres[kN] - pres[idx];
        if (d == 0 && idx < kN) return kInf;
        if (memo[idx][d] != -1) return memo[idx][d];
        int mx = -1;
        int ans = kInf;
        for(int j = idx; j < kN - (d - 1); ++j) {
            mx = max(mx,jobs[j]);
            ans = min(ans, mx + Helper(jobs, j + 1, d - 1));
        }
        memo[idx][d] = ans;
        return ans;
    }
    
};

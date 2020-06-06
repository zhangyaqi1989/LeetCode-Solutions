class Solution {
public:
    int maxArea(int h, int w, vector<int>& hs, vector<int>& vs) {
        sort(hs.begin(), hs.end());
        sort(vs.begin(), vs.end());
        int max_dh = max(hs[0], h - hs.back());
        int kNH = hs.size();
        for(int i = 1; i < kNH; ++i) {
            max_dh = max(max_dh, hs[i] - hs[i - 1]);
        }
        int max_dv = max(vs[0], w - vs.back());
        int kNW = vs.size();
        for(int i = 1; i < kNW; ++i) {
            max_dv = max(max_dv, vs[i] - vs[i - 1]);
        }
        // cout << max_dh << " " << max_dv << endl;
        return (long long) max_dh * max_dv % 1000000007;
    }
};

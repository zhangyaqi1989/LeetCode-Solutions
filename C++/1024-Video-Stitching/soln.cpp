bool mycmp(vector<int> & a, vector<int> & b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}
class Solution {
public:

    int videoStitching(vector<vector<int>>& clips, int T) {
        sort(clips.begin(), clips.end(), mycmp);
        int i = 0, n = clips.size();
        int start = 0, end = T;
        while (i < n && clips[i][1] < start) ++i;
        int cnt = 0;
        while (start < end) {
            vector<int> best = {-1, -1};
            while (i < n && clips[i][0] <= start) {
                if (clips[i][1] > best[1]) {
                    best[0] = clips[i][0];
                    best[1] = clips[i][1];
                }
                ++i;
            }
            // cout << best[1] << endl;
            if (best[1] == -1) return -1;
            ++cnt;
            start = best[1];
        }
        return cnt;
        
    }
};

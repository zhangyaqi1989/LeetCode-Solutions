class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            int a = intervals[i][0], b = intervals[i][1];
            bool covered = false;
            for(int j = 0; j < n; ++j) {
                if (i == j) continue;
                if (intervals[j][0] <= a && intervals[j][1] >= b) {
                    covered = true;
                    break;
                }
            }
            if(!covered) ++cnt;
        }
        return cnt;
    }
};

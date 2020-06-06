class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(), slots1.end());
        sort(slots2.begin(), slots2.end());
        const int kN1 = slots1.size(), kN2 = slots2.size();
        int i = 0, j = 0;
        while (i < kN1) {
            while (j < kN2 && slots2[j][1] < slots1[i][0]) ++j;
            while (j < kN2 && slots2[j][0] <= slots1[i][1]) {
                int s = max(slots1[i][0], slots2[j][0]);
                int e = min(slots1[i][1], slots2[j][1]);
                if (e - s >= duration) return {s, s + duration};
                ++j;
            }
            if (j > 0) --j;
            ++i;
        }
        return {};
    }
};

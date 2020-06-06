class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> cuts;
        for(int i = -1; i < n; ++i) cuts.push_back(i);
        for(int i = 0; i < n; ++i) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                cuts[r + 1] = min(cuts[r + 1], cuts[l] + 1);
                --l;
                ++r;
            }
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                cuts[r + 1] = min(cuts[r + 1], cuts[l] + 1);
                --l;
                ++r;
            }
        }
        return cuts.back();
    }
};

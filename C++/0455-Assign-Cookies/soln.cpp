class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, n = s.size();
        int ans = 0;
        for (int j = 0; j < g.size(); ++j) {
            while (i < n && s[i] < g[j]) ++i;
            if (i < n) {
                ans += 1;
                ++i;
            } else return ans;
        }
        return ans;
    }
};
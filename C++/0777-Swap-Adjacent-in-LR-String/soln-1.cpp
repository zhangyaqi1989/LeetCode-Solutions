class Solution {
public:
    bool canTransform(string start, string end) {
        vector<pair<char, int>> vs, ve;
        int n = start.size();
        for(int i = 0; i < n; ++i) {
            if (start[i] != 'X') vs.emplace_back(start[i], i);
            if (end[i] != 'X') ve.emplace_back(end[i], i);
        }
        int ns = vs.size(), ne = ve.size();
        if(ns != ne) return false;
        for(int i = 0; i < ns; ++i) {
            char c1 = vs[i].first, c2 = ve[i].first;
            int i1 = vs[i].second, i2 = ve[i].second;
            if (c1 == c2 && ((c1 == 'L' && i2 <= i1) || (c1 == 'R' && i2 >= i1))) continue;
            else return false;
        }
        return true;
    }
};

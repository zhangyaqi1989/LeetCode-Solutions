class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int ib = 0, nb = B.size();
        for(auto & int_a : A) {
            int s = int_a[0], e = int_a[1];
            while (ib < nb && s > B[ib][1]) ++ib;
            while (ib < nb && e >= B[ib][0]) {
                ans.push_back({max(s, B[ib][0]), min(e, B[ib][1])});
                ++ib;
            }
            if (ib > 0) --ib;
        }
        return ans;
    }
};

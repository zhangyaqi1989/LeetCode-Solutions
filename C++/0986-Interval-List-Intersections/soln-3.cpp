class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int ia = 0;
        int na = A.size(), nb = B.size();
        vector<vector<int>> ans;
        for(int ib = 0; ib < nb; ++ib) {
            int s = B[ib][0], e = B[ib][1];
            while (ia < na && A[ia][1] < s) ++ia;
            while (ia < na && A[ia][0] <= e) {
                ans.push_back({max(s, A[ia][0]), min(e, A[ia][1])});
                ++ia;
            }
            if (ia > 0) --ia;
        }
        return ans;
    }
};

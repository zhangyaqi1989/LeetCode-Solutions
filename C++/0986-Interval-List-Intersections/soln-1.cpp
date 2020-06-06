class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int idx = 0, n = B.size();
        vector<vector<int>> ans;
        for(auto & inta : A) {
            int sa = inta[0], ea = inta[1];
            while (idx < n && B[idx][1] < sa) ++idx;
            while (idx < n && B[idx][0] <= ea) {
                int sb = B[idx][0], eb = B[idx][1];
                ans.push_back({max(sa, sb), min(ea, eb)});
                ++idx;
            }
            if (idx > 0) --idx;
        }
        return ans;
        
    }
};

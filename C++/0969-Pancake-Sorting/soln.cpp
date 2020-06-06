class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        if (is_sorted(A.begin(), A.end())) return {};
        int n = A.size();
        vector<int> ans;
        for(int top = n; top >= 1; --top) {
            int idx = find(A.begin(), A.end(), top) - A.begin();
            if (idx == top - 1) continue;
            reverse(A.begin(), A.begin() + idx + 1);
            ans.push_back(idx + 1);
            reverse(A.begin(), A.begin() + top);
            ans.push_back(top);
        }
        return ans;
    }
};

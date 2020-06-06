class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        const int kN = arr.size();
        for(int i = 1; i < kN; ++i) {
            arr[i] ^= arr[i - 1];
        }
        vector<int> ans;
        for(const auto & q : queries) {
            int lo = q[0], hi = q[1];
            ans.push_back(lo == 0 ? arr[hi] : (arr[hi]^arr[lo - 1]));
        }
        return ans;
    }
};

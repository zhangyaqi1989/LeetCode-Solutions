class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        sort(A.begin(), A.end());
        int mod = 1e9 + 7;
        unordered_map<int, long long> tree;
        int n = A.size();
        for(int i = 0; i < n; ++i) {
            long long cnt = 1;
            for(int j = 0; j < i; ++j) {
                if (A[i] % A[j] == 0) {
                    cnt = (cnt + tree[A[j]] * tree[A[i] / A[j]]) % mod;
                }
            }
            tree[A[i]] = cnt % mod;
        }
        int ans = 0;
        for(auto & p : tree) {
            ans = (ans + p.second) % mod;
        }
        return ans;
    }
};

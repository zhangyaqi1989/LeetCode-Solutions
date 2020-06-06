class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A) {
        unordered_set<int> s(A.begin(), A.end());
        int mx = 0;
        int n = A.size();
        for(int i = 0; i < n - 2; ++i) {
            for(int j = i + 1; j < n - 1; ++j) {
                int a = A[i], b = A[j];
                int cur = 2;
                while (s.find(a + b) != s.end()) {
                    int c = a + b;
                    a = b;
                    b = c;
                    ++cur;
                }
                mx = max(mx, cur);
            }
        }
        return mx < 3 ? 0 : mx;
    }
};

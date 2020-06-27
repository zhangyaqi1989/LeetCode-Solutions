class Solution {
public:
    int kthFactor(int n, int k) {
        for(int f = 1; f <= n && k > 0; ++f) {
            if(n % f == 0) {
                if(--k == 0) return f;
            }
        }
        return -1;
    }
};

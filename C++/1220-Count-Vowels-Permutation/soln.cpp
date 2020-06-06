class Solution {
public:
    int countVowelPermutation(int n) {
        const long mod = 1000000007;
        long a = 1, e = 1, i = 1, o = 1, u = 1;
        for (int k = 1; k < n; ++k) {
            long na = (e + i + u) % mod;
            long ne = (a + i) % mod;
            long ni = (e + o) % mod;
            long no = i;
            long nu = (i + o) % mod;
            a = na;
            e = ne;
            i = ni;
            o = no;
            u = nu;            
        }
        return (a + e + i + o + u) % mod;

    }
};

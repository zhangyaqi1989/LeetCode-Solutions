class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string a = "a", b = "b";
        if (A < B) {
            swap(A, B);
            swap(a, b);
        }
        // A >= B
        int total_twos = A - (B + 1);
        int cnt = 0, twos = 0;
        string ans = "";
        while (A > 0 || B > 0) {
            if (cnt % 2 == 0) {
                if (twos < total_twos) {
                    ans += a + a;
                    A -= 2;
                    ++twos;
                } else {
                    ans += a;
                    --A;
                }
            } else {
                ans += b;
                --B;
            }
            ++cnt;
        }
        return ans;
    }
};

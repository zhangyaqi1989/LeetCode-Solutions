class Solution {
public:
    int getMaxRepetitions(string s1, int m1, string s2, int m2) {
        int i1 = 0, i2 = 0, n1 = s1.length(), n2 = s2.length();
        int ans = 0;
        int cur = 0;
        while (cur < m1) {
            if (s1[i1] == s2[i2]) {
                ++i2;
                if (i2 == n2) {
                    i2 = 0;
                    ++ans;
                }
            }
            ++i1;
            if (i1 == n1 && i2 == 0) {
               return int (m1 * 1.0 / (cur + 1) * ans / m2);
            }
            if (i1 == n1) {
                ++cur;
                i1 = 0;
            }

        }
        return ans / m2;
    }
};

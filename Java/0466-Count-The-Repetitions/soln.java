class Solution {
    public int getMaxRepetitions(String s1, int m1, String s2, int m2) {
        char[] c1 = s1.toCharArray(), c2 = s2.toCharArray();
        int i1 = 0, i2 = 0, ans = 0;
        int n1 = s1.length(), n2 = s2.length();
        int cur = 0;
        while (cur < m1) {
            if (c1[i1] == c2[i2]) {
                ++i2;
                if (i2 == n2) {
                    i2 = 0;
                    ++ans;
                }
            }
            ++i1;
            if (i1 == n1 && i2 == 0) {
                return (int) (m1 * 1.0 / (cur + 1) * ans / m2);
            }
            if (i1 == n1) {
                i1 = 0;
                ++cur;
            }
        }
        return ans / m2;
    }
}

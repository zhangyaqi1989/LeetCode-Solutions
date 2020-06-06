class Solution {
    public String strWithout3a3b(int A, int B) {
        String a, b;
        if (A >= B) {
            a = "a";
            b = "b";
        } else {
            a = "b";
            b = "a";
            int temp = B;
            B = A;
            A = temp;
        }
        StringBuilder sb = new StringBuilder();
        int cnt = 0, total_twos = A - (B + 1), twos = 0;
        while (A > 0 || B > 0) {
            if (cnt % 2 == 0) {
                if (twos < total_twos) {
                    sb.append(a + a);
                    A -= 2;
                    ++twos;
                } else {
                    sb.append(a);
                    --A;
                }
            } else {
                sb.append(b);
                --B;
            }
            ++cnt;
        }
        return sb.toString();
    }
}

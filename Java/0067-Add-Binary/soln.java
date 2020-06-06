class Solution {
    public String addBinary(String a, String b) {
        StringBuilder sb = new StringBuilder();
        int na = a.length(), nb = b.length();
        int ia = na - 1, ib = nb - 1;
        int carry = 0;
        while (ia >= 0 || ib >= 0 || carry > 0) {
            int va = (ia >= 0 ? a.charAt(ia) - '0' : 0);
            int vb = (ib >= 0 ? b.charAt(ib) - '0' : 0);
            int v = va + vb + carry;
            carry = v / 2;
            sb.append(Integer.toString(v % 2));
            ia = ia >= 0 ? ia - 1 : ia;
            ib = ib >= 0 ? ib - 1 : ib;
        }
        return sb.reverse().toString();
    }
}

class Solution {
    public boolean isLongPressedName(String name, String typed) {
        int i1 = 0, i2 = 0;
        int n1 = name.length(), n2 = typed.length();
        int cnt1 = 0, cnt2 = 0;
        while(i1 < n1) {
            char c1 = name.charAt(i1);
            if (i2 >= n2) return false;
            char c2 = typed.charAt(i2);
            cnt1 = 0;
            cnt2 = 0;
            while(i1 < n1 && name.charAt(i1) == c1) {
                ++cnt1;
                ++i1;
            }
            while(i2 < n2 && typed.charAt(i2) == c2) {
                ++cnt2;
                ++i2;
            }
            if (c1 != c2 || cnt2 < cnt1) return false;
        }
        return i2 == n2;
    }
}

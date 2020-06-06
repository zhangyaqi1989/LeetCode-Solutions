class Solution {
    public boolean checkRecord(String s) {
        int a = 0, l = 0;
        for(char ch : s.toCharArray()) {
            if (ch == 'A') ++a;
            if (ch == 'L') ++l;
            else {
                l = 0;
            }
            if (a > 1 || l > 2) return false;
        }
        return true;
    }
}

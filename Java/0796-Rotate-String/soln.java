class Solution {
    public boolean rotateString(String A, String B) {
        int nA = A.length(), nB = B.length();
        if (nA != nB) return false;
        for(int i = 0; i < nA; ++i) {
            String temp = A.substring(i) + A.substring(0, i);
            if (temp.equals(B)) return true;
        }
        return A.equals(B);
    }
}

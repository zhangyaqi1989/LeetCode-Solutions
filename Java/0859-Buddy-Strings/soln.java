class Solution {
    public boolean buddyStrings(String A, String B) {
        int nA = A.length(), nB = B.length();
        if (nA != nB) return false;
        int cnt = 0;
        char a = ' ', b = ' ';
        for(int i = 0; i < nA; ++i) {
            if (A.charAt(i) != B.charAt(i)) {
                if (cnt == 0) {
                    a = A.charAt(i);
                    b = B.charAt(i);
                } else {
                    if(a != B.charAt(i) || b != A.charAt(i))
                        return false;
                }
                ++cnt;
                if (cnt > 2) return false;
            }
        }
        if (cnt == 2) return true;
        else if (cnt == 1) return false;
        else {
            int[] chars = new int[256];
            for(char ch : A.toCharArray()) {
                ++chars[ch];
                if (chars[ch] == 2) return true;
            }
            return false;
        }
    }
}

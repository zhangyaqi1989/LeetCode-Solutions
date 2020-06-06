class Solution {
    public String gcdOfStrings(String str1, String str2) {
        int n = Math.min(str1.length(), str2.length());
        for(int i = n; i >= 1; --i) {
            String sub = str1.substring(0, i);
            if (divide(str1, sub) && divide(str2, sub)) return str1.substring(0, i);
        }
        return "";
    }
    
    public boolean divide(String s, String sub) {
        if (s.length() % sub.length() != 0) return false;
        for(int i = 0; i < s.length(); ++i) {
            if (s.charAt(i) != sub.charAt(i % sub.length())) return false;
        }
        return true;
    }
}

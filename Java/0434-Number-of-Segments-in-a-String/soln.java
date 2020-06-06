class Solution {
    public int countSegments(String s) {
        int idx = 0, n = s.length();
        int cnt = 0;
        while(idx < n) {
            if(s.charAt(idx) == ' ') {
                while(idx < n && s.charAt(idx) == ' ') ++idx;
            } else {
                while(idx < n && s.charAt(idx) != ' ') ++idx;
                ++cnt;
            }
        }
        return cnt;
    }
}

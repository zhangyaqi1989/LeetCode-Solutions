class Solution {
    public String findLongestWord(String s, List<String> d) {
        Collections.sort(d, (a, b) -> {
            if (a.length() == b.length()) return a.compareTo(b);
            return b.length() - a.length();
        });
        
        for(String t : d) {
            if (valid(s, t)) return t;
        }
        return "";
    }
    
    boolean valid(String s, String t) {
        if (t.length() > s.length()) return false;
        int j = 0, nt = t.length();
        for(char ch : s.toCharArray()) {
            if (ch == t.charAt(j)) {
                ++j;
                if (j == nt) return true;
            }
        }
        return false;
    }
}

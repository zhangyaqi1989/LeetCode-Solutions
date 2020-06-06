class Solution {
    public List<Boolean> camelMatch(String[] queries, String pattern) {
        List<Boolean> ans = new ArrayList<>();
        for(String word : queries) {
            ans.add(valid(word, pattern));
        }
        return ans;
    }
    
    public boolean valid(String word, String pattern) {
        int i = 0, n = pattern.length();
        int j = 0;
        for(; j < word.length(); ++j) {
            char ch = word.charAt(j);
            if (ch == pattern.charAt(i)) {
                ++i;
                if (i == n) break;
            } else {
                if (ch >= 'A' && ch <= 'Z') {
                    return false;
                }
            }
        }
        if (i != n) return false;
        for(int idx = j + 1; idx < word.length(); ++idx) {
            char ch = word.charAt(idx);
            if (ch >= 'A' && ch <= 'Z') return false;
        }
        return true;
    }
}

class Solution {
    public int distinctEchoSubstrings(String text) {
        List<Integer> [] idxes = new ArrayList[26];
        for(int i = 0; i < 26; ++i) idxes[i] = new ArrayList<Integer>();
        int n = text.length();
        Set<String> seen = new HashSet<>();
        for(int i = 0; i < n; ++i) {
            idxes[text.charAt(i) - 'a'].add(i);
        }
        for(int i = 0; i < n; ++i) {
            char ch = text.charAt(i);
            for(int j : idxes[ch - 'a']) {
                if (j >= i) break;
                if (2 * (j + 1) - (i + 1) < 0) continue;
                if (text.substring(2 * (j + 1) - (i + 1), j + 1).equals(text.substring(j + 1, i + 1))) 
                    seen.add(text.substring(2 * (j + 1) - (i + 1), i + 1));
            }
        }
        return seen.size();
    }
}

class Solution {
    public String boldWords(String[] words, String S) {
        int n = S.length();
        boolean [] tags = new boolean[n];
        for(String word : words) {
            int m = word.length();
            for(int i = 0; i < n - m + 1; ++i) {
                if (S.substring(i, i + m).equals(word)) {
                    for(int j = i; j < i + m; ++j) tags[j] = true;
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; ++i) {
            if (tags[i] && (i == 0 || !tags[i - 1])) sb.append("<b>");
            sb.append(S.charAt(i));
            if (tags[i] && (i == n - 1 || !tags[i + 1])) sb.append("</b>");
        }
        return sb.toString();
    }
}

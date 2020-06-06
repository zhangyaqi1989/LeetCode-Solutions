class Solution {
    public int shortestWordDistance(String[] words, String word1, String word2) {
        int i1 = -1, i2 = -1, ans = Integer.MAX_VALUE, n = words.length;
        boolean equal = word1.equals(word2);
        for(int i = 0; i < n; ++i) {
            String word = words[i];
            if (word.equals(word1)) i1 = i;
            if (word.equals(word2)) {
                if (equal) i1 = i2;
                i2 = i;
            }
            if (i1 != -1 && i2 != -1)
                ans = Math.min(ans, Math.abs(i1 - i2));
        }
        return ans;
    }
}

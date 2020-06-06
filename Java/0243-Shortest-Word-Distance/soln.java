class Solution {
    public int shortestDistance(String[] words, String word1, String word2) {
        int ans = Integer.MAX_VALUE;
        int i1 = -1, i2 = -1;
        int n = words.length;
        for(int i = 0; i < n; ++i) {
            String word = words[i];
            if(word1.equals(word)) {
                i1 = i;
            } else if (word2.equals(word)) {
                i2 = i;
            }
            if (i1 != -1 && i2 != -1)
                ans = Math.min(ans, Math.abs(i1 - i2));
        }
        return ans;
    }
}

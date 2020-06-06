class Solution {
    public int maxProduct(String[] words) {
        int n = words.length;
        int [] masks = new int[n];
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            String word = words[i];
            for(char ch : word.toCharArray()) {
                masks[i] |= (1 << (ch - 'a'));
            }
            for(int j = 0; j < i; ++j) {
                if ((masks[i] & masks[j]) == 0) 
                    ans = Math.max(ans, words[i].length() * words[j].length());
            }
        }
        return ans;
    }
}

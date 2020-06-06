class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        int n = words.length;
        int [] char_order = new int [26];
        for(int i = 0; i < 26; ++i) {
            char_order[order.charAt(i) - 'a'] = i;
        }
        for(int i = 1; i < n; ++i) {
            String w1 = words[i - 1], w2 = words[i];
            int m = Math.min(w1.length(), w2.length());
            boolean done = false;
            for(int j = 0; j < m; ++j) {
                char ch1 = w1.charAt(j), ch2 = w2.charAt(j);
                if (char_order[ch1 - 'a'] < char_order[ch2 - 'a']) {
                    done = true;
                    break;
                } else if (char_order[ch1 - 'a'] > char_order[ch2 - 'a']) return false;
            }
            if (!done && w1.length() > w2.length()) {
                return false;
            }
        }
        return true;
    }
}

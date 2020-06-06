class Solution {
    public String shortestCompletingWord(String licensePlate, String[] words) {
        int [] l_counter = count(licensePlate);
        int mn_len = Integer.MAX_VALUE;
        int ans = 0;
        int j = 0;
        for(String word : words) {
            int [] w_counter = count(word);
            boolean valid = true;
            for(int i = 0; i < 26; ++i) {
                if (l_counter[i] > w_counter[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid && word.length() < mn_len) {
                mn_len = word.length();
                ans = j;
            }
            ++j;
        }
        return words[ans];
        
    }
    
    private int [] count(String word) {
        int [] counter = new int [26];
        for(char ch : word.toCharArray()) {
            if (Character.isLetter(ch)) {
                if (ch >= 'a') {
                    ++counter[ch - 'a'];
                } else {
                    ++counter[ch - 'A'];
                }
            }
        }
        return counter;
    }
}

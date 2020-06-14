class Solution {
    public int countCharacters(String[] words, String chars) {
        int [] counter_chars = new int [26];
        for(char ch : chars.toCharArray()) ++counter_chars[ch - 'a'];
        int cnt = 0;
        for(String word : words) {
            int [] counter_word = new int [26];
            for(char ch : word.toCharArray()) ++counter_word[ch - 'a'];
            boolean valid = true;
            for(int i = 0; i < 26; ++i) {
                if(counter_word[i] > counter_chars[i]) {
                    valid = false;
                    break;
                }
            }
            if(valid) cnt += word.length();
        }
        return cnt;
    }
}

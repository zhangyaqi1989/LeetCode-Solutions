class Solution {
    public int countCharacters(String[] words, String chars) {
        // greedy:
        int [] cs = new int [26];
        for(char ch : chars.toCharArray()) ++cs[ch - 'a'];
        int cnt = 0;
        for(String word : words) {
            int [] temp = new int [26];
            for(char ch : word.toCharArray()) ++temp[ch - 'a'];
            boolean valid = true;
            for(int i = 0; i < 26; ++i) {
                if (temp[i] > cs[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) cnt += word.length();
        }
        return cnt;
    }
}

class Solution {
    public List<String> wordSubsets(String[] A, String[] B) {
        int [] chars = new int [26];
        for(String word : B) {
            int [] temp = new int [26];
            for(char ch : word.toCharArray()) {
                ++temp[ch - 'a'];
            }
            for(int i = 0; i < 26; ++i) {
                chars[i] = Math.max(chars[i], temp[i]);
            }
        }
        List<String> ans = new ArrayList<>();
        for(String word : A) {
            int [] chars_A = new int [26];
            for(char ch : word.toCharArray()) {
                ++chars_A[ch - 'a'];
            }
            boolean valid = true;
            for(int i = 0; i < 26; ++i) {
                if (chars[i] > chars_A[i]) {
                    valid = false;
                    break;
                }
            }
            if (valid) ans.add(word);
        }
        return ans;
    }
}

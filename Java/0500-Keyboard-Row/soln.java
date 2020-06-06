class Solution {
    public String[] findWords(String[] words) {
        List<String> ans_lst = new ArrayList<>();
        String [] rows = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        int [] chars = new int[26];
        for(int i = 0; i < 3; ++i) {
            String row = rows[i];
            for(char ch : row.toCharArray()) chars[ch - 'a'] = i;
        }
        for(String word : words) {
            String lower_word = word.toLowerCase();
            boolean valid = true, row_known = false;
            int row = 0;
            for(char ch : lower_word.toCharArray()) {
                if (!row_known) {
                    row_known = true;
                    row = chars[ch - 'a'];
                } else {
                    if (chars[ch - 'a'] != row) {
                        valid = false;
                        break;
                    }
                }
            }
            if (valid) ans_lst.add(word);
        }
        int n = ans_lst.size();
        String[] ans = new String[n];
        for(int i = 0; i < n; ++i) ans[i] = ans_lst.get(i);
        return ans;
    }
}

class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int [] chars = new int [26];
        for(char ch : p.toCharArray()) ++chars[ch - 'a'];
        int [] window = new int [26];
        List<Integer> ans = new ArrayList<>();
        int n = p.length();
        for(int i = 0; i < s.length(); ++i) {
            ++window[s.charAt(i) - 'a'];
            if(i >= n) --window[s.charAt(i - n) - 'a'];
            if(i >= n - 1) {
                boolean valid = true;
                for(int j = 0; j < 26; ++j) {
                    if(window[j] != chars[j]) {
                        valid = false;
                        break;
                    }
                }
                if (valid) ans.add(i - n + 1);
            }
        }
        return ans;
    }
}

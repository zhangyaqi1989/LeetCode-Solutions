class Solution {
    public String removeDuplicateLetters(String s) {
        int [] ridxes = new int [26];
        Arrays.fill(ridxes, -1);
        int n = s.length();
        for(int i = 0; i < n; ++i) ridxes[s.charAt(i) - 'a'] = i;
        boolean [] inserted = new boolean[26];
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n; ++i) {
            char ch = s.charAt(i);
            if (!inserted[ch - 'a']) {
                while (sb.length() > 0 && ch < sb.charAt(sb.length() - 1) && i < ridxes[sb.charAt(sb.length() - 1) - 'a']) {
                    char top = sb.charAt(sb.length() - 1);
                    sb.deleteCharAt(sb.length() - 1);
                    inserted[top - 'a'] = false;
                }
                inserted[ch - 'a'] = true;
                sb.append(ch);
            }
        }
        return sb.toString();
    }
}

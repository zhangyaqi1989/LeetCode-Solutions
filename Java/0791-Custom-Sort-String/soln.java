class Solution {
    public String customSortString(String S, String T) {
        int[] count = new int[26];
        for(char ch : T.toCharArray()) ++count[ch - 'a'];
        StringBuilder sb = new StringBuilder();
        for(char ch : S.toCharArray()) {
            while (count[ch - 'a']-- > 0) sb.append(ch);
        }
        for(char ch = 'a'; ch <= 'z'; ++ch) {
            while(count[ch - 'a']-- > 0) sb.append(ch);
        }
        return sb.toString();
    }
}

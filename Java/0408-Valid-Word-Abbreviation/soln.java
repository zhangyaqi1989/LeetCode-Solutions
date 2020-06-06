class Solution {
    public boolean validWordAbbreviation(String word, String abbr) {
        int i = 0, n = word.length();
        int num = 0;
        for(char ch : abbr.toCharArray()) {
            if (Character.isDigit(ch)) {
                if (num == 0 && ch == '0') return false;
                num = num * 10 + ch - '0';
            } else {
                i += num;
                num = 0;
                if (i >= n || ch != word.charAt(i)) return false;
                ++i;
            }
        }
        i += num;
        return i == n;
    }
}

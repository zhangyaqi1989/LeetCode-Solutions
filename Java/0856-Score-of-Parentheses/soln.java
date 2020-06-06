class Solution {
    public int scoreOfParentheses(String S) {
        int res = 0, layers = 0;
        for(int i = 0; i < S.length() - 1; ++i)
        {
            layers += S.charAt(i) == '(' ? 1 : -1;
            if (S.substring(i, i + 2).equals("()"))
                res += Math.pow(2, layers - 1);
        }
        return res;
    }
}
class Solution {
    public String orderlyQueue(String S, int K) {
        if (K > 1) {
            char[] chars = S.toCharArray();
            Arrays.sort(chars);
            return new String(chars);
        } else {
            String ans = S;
            char start = S.charAt(0);
            int n = S.length();
            for(int i = 1; i < n; ++i) {
                if (S.charAt(i) > start) continue;
                String temp = S.substring(i) + S.substring(0, i);
                if (ans.compareTo(temp) > 0) {
                    ans = temp;
                    start = temp.charAt(0);
                }
            }
            return ans;
        }
    }
}

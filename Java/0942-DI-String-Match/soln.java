class Solution {
    public int[] diStringMatch(String S) {
        int n = S.length();
        int lo = 0, hi = n;
        int [] ans = new int [n + 1];
        int i = 0;
        for(char ch : S.toCharArray()) {
            if (ch == 'I') {
                ans[i++] = lo++;
            } else {
                ans[i++] = hi--;
            }
        }
        ans[i] = lo;
        return ans;
    }
}

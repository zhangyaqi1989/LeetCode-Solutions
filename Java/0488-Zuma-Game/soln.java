class Solution {
    public int findMinStep(String board, String hand) {
        int [] counter = new int[91];
        for(char ch : hand.toCharArray()) ++counter[ch];
        board += "#";
        int ans = helper(board, counter);
        // System.out.println(ans);
        return ans > hand.length() ? -1 : ans;
    }
    
    public int helper(String board, int [] counter) {
        int n = board.length();
        if (n == 1) return 0;
        int ans = 10;
        int lo = 0;
        for(int hi = 0; hi < n; ++hi) {
            if (board.charAt(hi) != board.charAt(lo)) {
                char ch = board.charAt(lo);
                int need = Math.max(0, 3 - (hi - lo));
                if (counter[ch] >= need) {
                    // System.out.println(need);
                    counter[ch] -= need;
                    int temp = helper(board.substring(0, lo) + board.substring(hi), counter);
                    counter[ch] += need;
                    ans = Math.min(ans, temp + need);
                }
                lo = hi;
            }
        }
        // System.out.println(ans);
        return ans;
    }
}

class Solution {
    public int numFriendRequests(int[] ages) {
        final int N = 121;
        int [] counter = new int [N];
        for(int age : ages) ++counter[age];
        int ans = 0;
        for(int a = 1; a < N; ++a) {
            if(counter[a] != 0) {
                int cnt = 0;
                for(int b = 1; b < N; ++b) {
                    if (b <= 0.5 * a + 7 || b > a || (b > 100 && a < 100)) continue;
                    if(a == b) cnt += counter[b] - 1;
                    else cnt += counter[b];
                }
                ans += cnt * counter[a];
            }
        }
        return ans;
    }
}

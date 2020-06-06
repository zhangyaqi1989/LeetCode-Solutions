class Solution {
    public int[] getModifiedArray(int length, int[][] updates) {
        int [] records = new int[length + 1];
        for(int [] update : updates) {
            int s = update[0], e = update[1], inc = update[2];
            records[s] += inc;
            records[e + 1] -= inc;
        }
        int [] ans = new int[length];
        int acc = 0;
        for(int i = 0; i < length; ++i) {
            acc += records[i];
            ans[i] = acc;
        }
        return ans;
    }
}

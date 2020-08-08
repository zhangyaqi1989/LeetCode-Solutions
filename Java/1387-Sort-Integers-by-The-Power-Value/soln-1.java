class Solution {
    public int getKth(int lo, int hi, int k) {
        int [][] pairs = new int [hi - lo + 1][2];
        for(int i = 0; i < pairs.length; ++i) {
            int val = lo + i;
            int cnt = 0;
            while(val != 1) {
                ++cnt;
                if(val % 2 == 1) val = val * 3 + 1;
                else val /= 2;
            }
            pairs[i][0] = cnt;
            pairs[i][1] = lo + i;
        }
        Arrays.sort(pairs, (a, b)->(a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]));
        return pairs[k - 1][1];
    }
}

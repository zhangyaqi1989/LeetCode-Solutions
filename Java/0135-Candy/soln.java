class Solution {
    public int candy(int[] ratings) {
        int n = ratings.length;
        int [] candys = new int [n];
        Arrays.fill(candys, 1);
        for(int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i - 1]) candys[i] = candys[i - 1] + 1;
        }
        for(int j = n - 1; j > 0; --j) {
            if (ratings[j - 1] > ratings[j]) candys[j - 1] = Math.max(candys[j - 1], candys[j] + 1);
        }
        int ans = 0;
        for(int candy : candys) ans += candy;
        return ans;
    }
}

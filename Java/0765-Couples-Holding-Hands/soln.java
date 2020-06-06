class Solution {
    public int minSwapsCouples(int[] row) {
        int n = row.length;
        int cnt = 0;
        for(int i = 0; i < n; i += 2) {
            if (Math.abs(row[i] - row[i + 1]) != 1 || Math.min(row[i], row[i + 1]) % 2 == 1) {
                ++cnt;
                for(int j = i + 2; j < n; ++j) {
                    if(Math.abs(row[i] - row[j]) == 1 && Math.min(row[i], row[j]) % 2 == 0) {
                        int temp = row[i + 1];
                        row[i + 1] = row[j];
                        row[j] = temp;
                    }
                }
            }
        }
        return cnt;
    }
}

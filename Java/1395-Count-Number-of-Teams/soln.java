class Solution {
    public int numTeams(int[] rating) {
        int cnt = 0, n = rating.length;
        for(int i = 0; i < n; ++i) {
            int [] less = new int [2];
            int [] greater = new int [2];
            for(int j = 0; j < n; ++j) {
                if (rating[i] < rating[j]) {
                    ++less[j > i ? 1 : 0];
                } else if (rating[i] > rating[j]) {
                    ++greater[j > i ? 1 : 0];
                }
            }
            cnt += less[0] * greater[1] + greater[0] * less[1];
        }
        return cnt;
    }
}

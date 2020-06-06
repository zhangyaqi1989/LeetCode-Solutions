class Solution {
    public int numSubmatrixSumTarget(int[][] A, int target) {
        int m = A.length, n = A[0].length;
        int cnt = 0;
        for (int left = 0; left < n; ++left) {
            int [] temp = new int [m];
            for(int right = left; right < n; ++right) {
                for(int i = 0; i < m; ++i) {
                    temp[i] += A[i][right];
                }
                cnt += helper(temp, target);
            }
        }
        return cnt;
    }
    
    public int helper(int [] arr, int target) {
        int acc = 0;
        Map<Integer, Integer> memo = new HashMap<>();
        memo.put(0, 1);
        int cnt = 0;
        for(int num : arr) {
            acc += num;
            cnt += memo.getOrDefault(acc - target, 0);
            memo.put(acc, memo.getOrDefault(acc, 0) + 1);
        }
        return cnt;
    }
}

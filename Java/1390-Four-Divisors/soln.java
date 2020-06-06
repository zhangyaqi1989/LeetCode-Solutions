class Solution {
    public Map<Integer, Integer> memo;
    public int sumFourDivisors(int[] nums) {
        memo = new HashMap<>();
        int ans = 0;
        for(int num : nums) ans += sumDivisors(num);
        return ans;
    }
    
    public int sumDivisors(int num) {
        if (memo.containsKey(num)) return memo.get(num);
        int sum = 0, cnt = 0;
        for(int f = 1; f * f <= num; ++f) {
            if (num % f == 0) {
                sum += f;
                ++cnt;
                if (f * f != num) {
                    sum += num / f;
                    ++cnt;
                }
                if (cnt > 4) {
                    memo.put(num, 0);
                    return 0;
                }
            }
        }
        if (cnt != 4) sum = 0;
        memo.put(num, sum);
        return sum;
    }
    
    
}

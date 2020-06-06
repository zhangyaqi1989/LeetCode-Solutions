class Solution {
    public int singleNumber(int[] nums) {
        long ans = 0;
        Set<Integer> s = new HashSet<>();
        for(int num : nums) s.add(num);
        for(int num : s) ans += num;
        ans *= 3;
        for(int num : nums) ans -= num;
        return (int) (ans / 2);
    }
}

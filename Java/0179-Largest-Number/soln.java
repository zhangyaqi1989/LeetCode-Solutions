class Solution {
    public String largestNumber(int[] nums) {
        int n = nums.length;
        String [] num_strs = new String[n];
        for(int i = 0; i < n; ++i) num_strs[i] = Integer.toString(nums[i]);
        Arrays.sort(num_strs, (a, b) -> ((b + a).compareTo(a + b)));
        String ans = String.join("", num_strs);
        int i = 0, m = ans.length();
        while (i < m - 1 && ans.charAt(i) == '0') ++i;
        return ans.substring(i);
    }
}

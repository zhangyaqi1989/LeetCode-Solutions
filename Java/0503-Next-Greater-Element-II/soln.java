class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        Stack<Integer> stk = new Stack<>();
        int [] ans = new int [n];
        Arrays.fill(ans, -1);
        for(int i = 0; i < 2 * n; ++i) {
            int j = i % n;
            while(!stk.isEmpty() && nums[j] > nums[stk.peek()]) {
                ans[stk.pop()] = nums[j];
            }
            stk.push(j);
        }
        return ans;
    }
}

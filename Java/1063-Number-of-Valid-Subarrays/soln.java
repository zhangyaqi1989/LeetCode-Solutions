class Solution {
    public int validSubarrays(int[] nums) {
        int cnt = 0, n = nums.length;
        Stack<Integer> stk = new Stack<>();
        for(int i = 0; i < n; ++i) {
            while(!stk.empty() && nums[i] < nums[stk.peek()]) {
                cnt += i - stk.peek();
                stk.pop();
            }
            stk.push(i);
        }
        while(!stk.empty()) {cnt += n - stk.peek(); stk.pop();}
        return cnt;
    }
}

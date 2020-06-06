class Solution {
    public boolean find132pattern(int[] nums) {
        int two = Integer.MIN_VALUE;
        int n = nums.length;
        Stack<Integer> stk = new Stack<>();
        for(int i = n - 1; i >= 0; --i) {
            if (two > nums[i]) return true;
            while(!stk.isEmpty() && nums[i] > stk.peek()) {
                int num = stk.pop();
                if (num > two) two = num;
            }
            stk.push(nums[i]);
        }
        return false;
    }
}

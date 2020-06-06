class Solution {
    public boolean verifyPreorder(int[] preorder) {
        Stack<Integer> stk = new Stack<>();
        int pre = Integer.MIN_VALUE;
        for(int val : preorder) {
            if (val < pre) return false;
            while (!stk.isEmpty() && val > stk.peek()) {
                if (stk.peek() <= pre) return false;
                pre = stk.pop();
            }
            stk.push(val);
        }
        return true;
    }
}

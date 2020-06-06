class Solution {
    public int[] addNegabinary(int[] arr1, int[] arr2) {
        int i = arr1.length - 1, j = arr2.length - 1, carry = 0;
        Stack<Integer> stk = new Stack<>();
        while (i >= 0 || j >= 0 || carry != 0) {
            if (i >= 0) carry += arr1[i--];
            if (j >= 0) carry += arr2[j--];
            stk.push(carry & 1);
            carry = -(carry >> 1);
        }
        while (stk.size() > 1 && stk.peek() == 0) stk.pop();
        int [] ans = new int [stk.size()];
        int idx = 0;
        while (!stk.isEmpty()) ans[idx++] = stk.pop();
        return ans;
    }
}

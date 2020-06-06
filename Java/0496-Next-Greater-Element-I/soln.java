class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Stack<Integer> stk = new Stack<>();
        int n = nums2.length;
        Map<Integer, Integer> m = new HashMap<>();
        for(int i = 0; i < n; ++i) {
            int num = nums2[i];
            while (!stk.isEmpty() && num > stk.peek()) {
                m.put(stk.peek(), num);
                stk.pop();
            }
            stk.push(num);
        }
        int [] ans = new int[nums1.length];
        Arrays.fill(ans, -1);
        for(int i = 0; i < nums1.length; ++i) {
            if (m.containsKey(nums1[i])) ans[i] = m.get(nums1[i]);
        }
        return ans;
    }
}

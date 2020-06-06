class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer, Integer> idxes = new HashMap<>();
        int n = nums1.length;
        for(int i = 0; i < n; ++i) {
            idxes.put(nums1[i], i);
        }
        int [] ans = new int [n];
        Arrays.fill(ans, -1);
        Stack<Integer> stk = new Stack<>();
        for(int i = 0; i < nums2.length; ++i) {
            while(!stk.isEmpty() && nums2[i] > nums2[stk.peek()]) {
                int top = nums2[stk.pop()];
                if (idxes.containsKey(top))
                    ans[idxes.get(top)] = nums2[i];
            }
            stk.push(i);
        }
        return ans;
    }
}

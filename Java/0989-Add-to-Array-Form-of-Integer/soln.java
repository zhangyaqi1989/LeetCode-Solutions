class Solution {
    public List<Integer> addToArrayForm(int[] A, int K) {
        List<Integer> ans = new ArrayList<>();
        int n = A.length;
        int idx = n - 1, carry = 0;
        while(idx >= 0 || K != 0 || carry != 0) {
            int v1 = (idx >= 0 ? A[idx--] : 0);
            int v2 = K % 10;
            K /= 10;
            int v = v1 + v2 + carry;
            carry = v / 10;
            ans.add(v % 10);
        }
        Collections.reverse(ans);
        return ans;
    }
}

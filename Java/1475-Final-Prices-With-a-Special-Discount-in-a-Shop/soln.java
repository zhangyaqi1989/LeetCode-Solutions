class Solution {
    public int[] finalPrices(int[] prices) {
        int n = prices.length;
        int [] ans = new int [n];
        Stack<Integer> st = new Stack<>();
        for(int i = 0; i < n; ++i) {
            ans[i] = prices[i];
            while(!st.isEmpty() && prices[i] <= prices[st.peek()]) {
                ans[st.peek()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
}

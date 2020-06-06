class Solution {
    public int[] dailyTemperatures(int[] T) {
        int n = T.length;
        int[] ans = new int[n];
        Stack<Integer> s = new Stack<>();
        for(int i = 0; i < n; ++i) {
            while(!s.isEmpty() && T[i] > T[s.peek()]) {
                ans[s.peek()] = i - s.peek();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
}

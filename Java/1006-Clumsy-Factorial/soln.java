class Solution {
    public int clumsy(int N) {
        Stack<Integer> stack = new Stack<>();
        stack.push(N);
        int idx = 0;
        while (N > 1) {
            --N;
            if (idx == 2) {
                stack.push(N);
            } else if (idx == 3) {
                stack.push(-N);
            } else if (idx == 0) {
                int top = stack.pop();
                stack.push(top * N);
            } else {
                int top = stack.pop();
                if (top >= 0) stack.push(top / N);
                else stack.push(-((-top) / N));
            }
            idx = (idx + 1) % 4;
        }
        int ans = 0;
        while (!stack.empty()) {
            ans += stack.pop();
        }
        return ans;
    }
}

class Solution {
    public int[] exclusiveTime(int n, List<String> logs) {
        int [] ans = new int [n];
        Stack<int []> stk = new Stack<>();
        for(String log : logs) {
            String [] tokens = log.split(":");
            int idx = Integer.parseInt(tokens[0]);
            int time = Integer.parseInt(tokens[2]);
            String s = tokens[1];
            if (s.equals("start")) {
                if (!stk.isEmpty()) {
                    ans[stk.peek()[0]] += time - stk.peek()[1];
                }
                stk.push(new int [] {idx, time});
            } else {
                ans[stk.peek()[0]] += time - stk.peek()[1] + 1;
                stk.pop();
                if (!stk.isEmpty()) stk.peek()[1] = time + 1;
            }
        }
        return ans;
    }
}

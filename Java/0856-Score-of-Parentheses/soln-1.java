class Solution {
    public int scoreOfParentheses(String S) {
        Stack<String> stk = new Stack<>();
        for(char ch : S.toCharArray()) {
            if (ch == '(') {
                stk.push("(");
            } else {
                int sum = 0;
                while(!stk.peek().equals("(")) {
                    sum += Integer.parseInt(stk.pop());
                }
                stk.pop();
                if (sum == 0) sum = 1;
                else sum *= 2;
                stk.push(Integer.toString(sum));
            }
        }
        int ans = 0;
        while(!stk.isEmpty()) ans += Integer.parseInt(stk.pop());
        return ans;
    }
}

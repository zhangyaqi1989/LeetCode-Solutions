class Solution {
    public String makeGood(String s) {
        Stack<Character> stk = new Stack<>();
        final int DIFF = 'a' - 'A';
        for(char ch : s.toCharArray()) {
            if(!stk.isEmpty() && Math.abs(ch - stk.peek()) == DIFF) {
                stk.pop();
            } else {
                stk.push(ch);
            }
        }
        StringBuilder sb = new StringBuilder();
        while(!stk.isEmpty()) {
            sb.append(stk.peek());
            stk.pop();
        }
        return sb.reverse().toString();
    }
}

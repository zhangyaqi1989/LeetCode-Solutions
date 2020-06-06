class Solution {
    public String removeDuplicates(String S) {
        Stack<Character> stk = new Stack<>();
        for(char ch : S.toCharArray()) {
            if (!stk.isEmpty() && stk.peek() == ch) {
                stk.pop();
            } else {
                stk.push(ch);
            }
        }
        StringBuilder sb = new StringBuilder();
        while(!stk.isEmpty()) {
            sb.append(stk.pop());
        }
        return sb.reverse().toString();
    }
}

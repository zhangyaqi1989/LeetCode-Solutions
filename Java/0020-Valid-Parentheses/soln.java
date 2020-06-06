class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<Character>();
        for (int i = 0; i < s.length(); ++i)
        {
            if(stack.empty() || (s.charAt(i) == '(' || s.charAt(i) == '[' || s.charAt(i) == '{'))
                stack.push(s.charAt(i));
            else
            {
                String temp = Character.toString(stack.pop()) + s.charAt(i);
                if (!temp.equals("()") && !temp.equals("[]") && !temp.equals("{}"))
                    return false;
            }
        }
        return stack.empty();
    }
}

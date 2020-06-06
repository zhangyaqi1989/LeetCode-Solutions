class Solution {
    public List<Integer> diffWaysToCompute(String input) {
        return helper(input, 0, input.length());
    }
    
    public List<Integer> helper(String input, int lo, int hi) {
        boolean isdigit = true;
        for(int i = lo; i < hi; ++i) {
            if (!Character.isDigit(input.charAt(i))) {
                isdigit = false;
                break;
            }
        }
        // System.out.println(input.substring(lo, hi));
        List<Integer> ans = new ArrayList<>();
        if (isdigit) {
            ans.add(Integer.parseInt(input.substring(lo, hi)));
            return ans;
        }
        
        for(int i = lo; i < hi; ++i) {
            char ch = input.charAt(i);
            if(!Character.isDigit(ch)) {
                List<Integer> lefts = helper(input, lo, i);
                List<Integer> rights = helper(input, i + 1, hi);
                for(int left : lefts) {
                    for(int right : rights) {
                        ans.add(func(ch, left, right));
                    }
                }
            }
        }
        return ans;
    }
    
    public int func(char op, int left, int right) {
        if (op == '+') return left + right;
        else if (op == '-') return left - right;
        else return left * right;
    }
}

class Solution {
    public String convertToBase7(int num) {
        if (num == 0) return "0";
        boolean neg = num < 0;
        StringBuilder sb = new StringBuilder();
        num = Math.abs(num);
        while (num != 0) {
            sb.append(Integer.toString(num % 7));
            num /= 7;
        }
        
        return neg ? "-" + sb.reverse().toString() : sb.reverse().toString();
    }
}

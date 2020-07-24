class Solution {
    public String largestMultipleOfThree(int[] digits) {
        int [] m1 = {1, 4, 7, 2, 5, 8};
        int [] m2 = {2, 5, 8, 1, 4, 7};
        int [] counter = new int [10];
        int sum = 0;
        for(int d : digits) {
            ++counter[d];
            sum += d;
        }
        while(sum % 3 != 0) {
            for(int d : (sum % 3 == 1 ? m1 : m2)) {
                if(counter[d] > 0) {
                    --counter[d];
                    sum -= d;
                    break;
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        for(char d = '9'; d >= '0'; --d) {
            if(counter[d - '0'] > 0) {
                for(int i = 0; i < counter[d - '0']; ++i) {
                    sb.append(d);
                }
            }
        }
        String ans = sb.toString();
        if(ans.isEmpty()) return "";
        return ans.charAt(0) == '0' ? "0" : ans;
    }
}

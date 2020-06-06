class Solution {
    public int rotatedDigits(int N) {
        int cnt = 0;
        for(int i = 1; i <= N; ++i) {
            if (isGood(i)) ++cnt;
        }
        return cnt;
    }
    
    public boolean isGood(int N) {
        String s = Integer.toString(N);
        boolean change = false;
        for(char ch : s.toCharArray()) {
            if (ch == '3' || ch == '4' || ch == '7') return false;
            else if (ch == '2' || ch == '5' || ch == '6' || ch == '9') change = true;
        }
        return change;
    }
}

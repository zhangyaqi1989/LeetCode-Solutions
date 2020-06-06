class Solution {
    public int dayOfYear(String date) {
        int [] days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        String [] tokens = date.split("-");
        int year = Integer.parseInt(tokens[0]), month = Integer.parseInt(tokens[1]), day = Integer.parseInt(tokens[2]);
        if (isLeapYear(year)) days[1] = 29;
        int ans = 0;
        for(int m = 0; m < month - 1; ++m) {
            ans += days[m];
        }
        return ans + day;
    }
    
    private boolean isLeapYear(int year) {
        if (year % 4 != 0) return false;
        else if (year % 100 != 0) return true;
        return year % 400 == 0;
    }
}

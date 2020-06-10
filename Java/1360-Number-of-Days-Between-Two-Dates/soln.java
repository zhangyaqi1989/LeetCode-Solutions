class Solution {
    public int daysBetweenDates(String date1, String date2) {
        return Math.abs(dayOfYear(date1) - dayOfYear(date2));
    }
    
    private int dayOfYear(String date) {
        int [] days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        String [] tokens = date.split("-");
        int year = Integer.parseInt(tokens[0]), month = Integer.parseInt(tokens[1]), day = Integer.parseInt(tokens[2]);
        if (isLeapYear(year)) days[1] = 29;
        int ans = 0;
        for(int y = 1971; y < year; ++y) {
            if (isLeapYear(y)) ans += 366;
            else ans += 365;
        }
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

class Solution {
    public int numberOfDays(int Y, int M) {
        int [] days = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(M == 2) {
            return isLeapYear(Y) ? 29 : 28;
        } else {
            return days[M];
        }
    }
    
    private boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
}

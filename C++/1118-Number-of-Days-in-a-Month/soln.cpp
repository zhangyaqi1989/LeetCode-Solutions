class Solution {
public:
    int numberOfDays(int Y, int M) {
        int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(M == 2) {
            return IsLeapYear(Y) ? 29 : 28;
        } else {
            return days[M];
        }
    }
    
private:
    bool IsLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    }
};

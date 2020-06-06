class Solution {
public:
    int rotatedDigits(int N) {
        int cnt = 0;
        for(int i = 1; i <= N; ++i) if (isGood(i)) ++cnt;
        return cnt;
    }
    
    bool isGood(int N) {
        bool change = false;
        for(char ch : to_string(N)) {
            if (ch == '3' || ch == '4' || ch == '7') {return false;}
            else if (ch == '6' || ch == '9' || ch == '2' || ch == '5') change = true;
        }
        return change;
    }
};

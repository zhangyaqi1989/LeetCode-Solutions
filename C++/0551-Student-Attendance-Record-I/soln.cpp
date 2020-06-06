class Solution {
public:
    bool checkRecord(string s) {
        int a = 0, l = 0;
        for(auto ch : s)
        {
            if(ch == 'A') a++;
            if(ch == 'L') l++;
            else l = 0;
            if(a >= 2 || l > 2) return false;
        }
        return true;
    }
};
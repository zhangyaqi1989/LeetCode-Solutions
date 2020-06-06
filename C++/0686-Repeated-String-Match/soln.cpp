class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        int na = A.length(), nb = B.length();
        int repeat = (nb + na - 1) / na;
        string rA = "";
        for(int i = 0; i < repeat; ++i) rA += A;
        if (rA.find(B) != string::npos) return repeat;
        rA += A;
        if (rA.find(B) != string::npos) return repeat + 1;
        return -1;
    }
};

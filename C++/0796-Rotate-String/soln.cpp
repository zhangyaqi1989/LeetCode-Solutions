class Solution {
public:
    bool rotateString(string A, string B) {
        int nA = A.length(), nB = B.length();
        if (nA != nB) return false;
        for(int i = 0; i < nA; ++i) {
            string temp = A.substr(i) + A.substr(0, i);
            if (temp == B) return true;
        }
        return A == B;
    }
};

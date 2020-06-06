class Solution {
public:
    string freqAlphabets(string s) {
        const int kN = s.length();
        string ans;
        for(int i = 0; i < kN; ) {
            if (i + 2 < kN && s[i + 2] == '#') {
                int num = stoi(s.substr(i, 2)) - 10;
                ans += string(1, 'j' + num);
                i += 3;
            } else {
                int num = s[i] - '1';
                ans += string(1, 'a' + num);
                i += 1;
            }
        }
        return ans;
    }
};

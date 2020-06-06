class Solution {
public:
    string getHint(string secret, string guess) {
        int m[10] = {0};
        int bull = 0, cow = 0, n = secret.length();
        for(int i = 0; i < n; ++i) {
            if (secret[i] == guess[i]) ++bull;
            else ++m[secret[i] - '0'];
        }
        for(int i = 0; i < n; ++i) {
            if (secret[i] != guess[i]) {
                if (m[guess[i] - '0'] > 0) {
                    --m[guess[i] - '0'];
                    ++cow;
                }
            }
        }
        return to_string(bull) + "A" + to_string(cow) + "B";
    }
};

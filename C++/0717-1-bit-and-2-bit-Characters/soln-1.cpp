class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0, n = bits.size();
        while (i + 1 < n) {
            if (bits[i] == 1) i += 2;
            else i += 1;
        }
        return i == n - 1;
    }
};

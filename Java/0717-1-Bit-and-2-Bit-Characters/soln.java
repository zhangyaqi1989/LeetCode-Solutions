class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int i = 0, n = bits.length;
        while (i + 1 < n) {
            if (bits[i] == 1) i += 2;
            else ++i;
        }
        return i == n - 1;
    }
}

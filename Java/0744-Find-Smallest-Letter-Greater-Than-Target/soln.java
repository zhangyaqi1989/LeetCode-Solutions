class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int lo = 0, hi = letters.length;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (letters[mid] > target) hi = mid;
            else lo = mid + 1;
        }
        return lo == letters.length ? letters[0] : letters[lo];
    }
}

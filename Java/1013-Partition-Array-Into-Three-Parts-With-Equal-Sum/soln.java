class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        for(int num : A) sum += num;
        if (sum % 3 != 0) return false;
        int cur = 0, cnt = 0, avg = sum / 3;
        for(int num : A) {
            cur += num;
            if (cur == avg) {
                ++cnt;
                cur = 0;
                if (cnt == 3) return true;
            }
        }
        return false;
    }
}

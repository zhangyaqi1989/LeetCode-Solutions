class Solution {
    public boolean canArrange(int[] arr, int k) {
        int [] mods = new int [k];
        for(int num : arr) {
            int mod = num % k;
            if(mod < 0) mod += k;
            ++mods[mod];
        }
        if(mods[0] % 2 != 0) return false;
        for(int mod = 1; mod < k; ++mod) {
            if(mods[mod] > 0 && mods[k - mod] != mods[mod]) return false;
        }
        return true;
    }
}

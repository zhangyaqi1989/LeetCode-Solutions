class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mods(k, 0);
        for(int num : arr) {
            int mod = num % k;
            if(mod < 0) mod += k;
            ++mods[mod];
        }
        if(mods[0] % 2 != 0) return false;
        for(int mod = 1; mod < k; ++mod) {
            if(mods[mod] != 0) {
                int need = k - mod;
                if(mods[need] != mods[mod]) return false;
            }
        }
        return true;
    }
};

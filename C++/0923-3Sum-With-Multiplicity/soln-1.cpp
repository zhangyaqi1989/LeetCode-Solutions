class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        // i < j < k and A[i] + A[j] + A[k] == target
        vector<int> counter(101, 0);
        for(int num : A) ++counter[num];
        const int kMod = 1e9 + 7;
        int ans = 0;
        for(int a = 0; a <= 100; ++a) {
            for(int b = a; b <= 100; ++b) {
                for(int c = b; c <= 100; ++c) {
                    if (a + b + c == target) {
                        int aa = counter[a]--;
                        int bb = counter[b]--;
                        int cc = counter[c]--;
                        if(aa > 0 && bb > 0 && cc > 0) {
                            int add = 0;
                            if(a == b && b == c) {
                                add = (long long) aa * bb * cc / 6 % kMod;
                            } else if (a == b || b == c) {
                                add = (long long) aa * bb * cc / 2 % kMod;
                            } else {
                                add = (long long) aa * bb * cc % kMod;
                            }
                            ans = ((long long) ans + add) % kMod;
                        }
                        counter[a]++;
                        counter[b]++;
                        counter[c]++;
                    }
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int countTriplets(vector<int>& A) {
        vector<int> memo(1 << 16, -1);
        int ans = 0;
        for(int a : A) {
            for(int b : A) {
                int ab = a & b;
                if (memo[ab] != -1) ans += memo[ab];
                else {
                    int cnt = 0;
                    for(int c : A) {
                        if ((ab & c) == 0) ++cnt;
                    }
                    memo[ab] = cnt;
                    ans += cnt;
                }
            }
        }
        return ans;
    }
};

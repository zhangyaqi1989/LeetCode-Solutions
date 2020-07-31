class Solution {
public:
    bool isArmstrong(int N) {
        long long ans = 0;
        string N_str = to_string(N);
        int k = N_str.length();
        int memo_N = N;
        while(N) {
            int d = N % 10;
            ans += pow(d, k);
            N /= 10;
        }
        return ans == memo_N;
    }
};

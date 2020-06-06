class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        if (D.empty()) return 0;
        ++N;
        vector<int> digits;
        const int kN = D.size();
        for(int i = 0; i < kN; ++i) digits.push_back(D[i][0] - '0');
        int width = to_string(N).length();
        int ans = 0;
        for(int i = 1; i < width; ++i) {
            ans += pow(kN, i);
        }
        vector<int> ds;
        int temp = N;
        while (temp) {
            ds.push_back(temp % 10);
            temp /= 10;
        }
        reverse(ds.begin(), ds.end());
        const int kM = ds.size();
        for(int i = 0; i < kM; ++i) {
            int d = ds[i];
            for(int j = 0; j < kN; ++j) {
                if (digits[j] >= d) break;
                ans += pow(kN, kM - 1 - i);
            }
            if (find(digits.begin(), digits.end(), d) == digits.end()) break;
        }
        return ans;
    }
};

class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int mn = *min_element(A.begin(), A.end());
        int cnt = 0;
        while (mn) {
            cnt += mn % 10;
            mn /= 10;
        }
        return cnt & 1 ? 0 : 1;
    }
};

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0);
        if (sum % 3 != 0) return false;
        int avg = sum / 3;
        int cur = 0, cnt = 0;
        for(int num : A) {
            cur += num;
            if (cur == avg) {
                cur = 0;
                ++cnt;
                if (cnt == 3) return true;
            }
        }
        return false;
    }
};

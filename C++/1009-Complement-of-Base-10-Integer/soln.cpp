class Solution {
public:
    int bitwiseComplement(int N) {
        vector<int> digits;
        if(N == 0) digits.push_back(1);
        else {
            while (N != 0) {
                digits.push_back(1 - N % 2);
                N /= 2;
            }
        }
        int ans = 0;
        for(auto it = digits.rbegin(); it != digits.rend(); ++it) {
            ans = ans * 2 + (*it);
        }
        return ans;
    }
};

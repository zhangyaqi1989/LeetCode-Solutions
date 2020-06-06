class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        reverse(A.begin(), A.end());
        int carry = 0;
        int n = A.size();
        A[0] += K;
        for(int i = 0; i < n; ++i) {
            int temp = A[i] + carry;
            carry = temp / 10;
            A[i] = temp % 10;
        }
        while (carry) {
            A.push_back(carry % 10);
            carry /= 10;
        }
        reverse(A.begin(), A.end());
        return A;
    }
};

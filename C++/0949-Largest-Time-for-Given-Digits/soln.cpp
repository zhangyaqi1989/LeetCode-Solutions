class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        string ans = "";
        int time = -1;
        int n = 4 * 3 * 2 * 1;
        for (int i = 0; i < n; ++i) {
            int temp = convert_to_time(A);
            if (temp > time) {
                time = temp;
                ans = to_string(A[0]) + to_string(A[1]) + ":" + to_string(A[2]) + to_string(A[3]);
            }
            next_permutation(A.begin(), A.end());
        }
        return ans;
    }
    
    int convert_to_time(vector<int> & A) {
        int a, b, c, d;
        a = A[0], b = A[1], c = A[2], d = A[3];
        int h = a * 10 + b;
        int m = c * 10 + d;
        if (h < 24 && m < 60) return h * 24 + m;
        return -1;
    }
};
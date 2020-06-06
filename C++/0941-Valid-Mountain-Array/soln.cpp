class Solution {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) return false;
        bool increase = true;
        bool has_increase = false;
        for (int i = 0; i < A.size() - 1; ++i) {
            int a = A[i];
            int b = A[i + 1];
            if (increase) {
                if (b < a)
                    increase = false;
                else if (a == b)
                    return false;
                else
                    has_increase = true;
            } else {
                if (b >= a)
                    return false;
            }
        }
        return has_increase && !increase;
    }
};
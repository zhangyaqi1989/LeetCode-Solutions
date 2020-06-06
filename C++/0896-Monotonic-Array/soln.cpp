class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int increased = 0;
        for(int i = 0; i < A.size() - 1; ++i)
        {
            if(increased == 0)
            {
                if (A[i + 1] > A[i]) increased = 1;
                else if (A[i + 1] < A[i]) increased = -1;
                
            } else
            {
                if((increased > 0 && A[i + 1] < A[i]) || (increased < 0 && A[i + 1] > A[i]))
                    return false;
            }
        }
        return true;
    }
};
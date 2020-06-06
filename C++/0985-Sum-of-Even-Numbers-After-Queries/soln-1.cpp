class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> ans;
        int evens = 0;
        for(int num : A) {
            if (num % 2 == 0) evens += num;
        }
        for(vector<int> & q : queries) {
            int val = q[0];
            int i = q[1];
            if (A[i] % 2 == 0) evens -= A[i];
            if ((val + A[i]) % 2 == 0) {
                evens += val + A[i];
            }
            ans.push_back(evens);
            A[i] += val;
        }
        return ans;
    }
};

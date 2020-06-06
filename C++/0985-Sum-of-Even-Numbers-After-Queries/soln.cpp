class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int evens = 0;
        int n = A.size();
        for(int num : A) {
            if ((num & 1) == 0) {evens += num;}
        }
        // cout << evens << endl;
        vector<int> ans;
        for(auto & query : queries) {
            int val = query[0], idx = query[1];
            if ((A[idx] & 1) == 0) {
                A[idx] += val;
                if ((val & 1) == 0) evens += val;
                else evens -= (A[idx] - val);
            } else {
                A[idx] += val;
                if ((val & 1) == 1) evens += A[idx];
            }
            ans.push_back(evens);
        }
        return ans;
    }
};

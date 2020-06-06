class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int, int> AB, CD;
        int n = A.size();
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                AB[A[i] + B[j]]++;
                CD[C[i] + D[j]]++;
            }
        }
        int cnt = 0;
        for(auto & it : AB) {
            // cout << it.first << endl;
            cnt += it.second * (CD[-it.first]);
        }
        return cnt;
    }
};

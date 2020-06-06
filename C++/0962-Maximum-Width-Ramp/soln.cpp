class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        // find a O(n) ALG
        // for each item, find right most item that is larger or equal to it
        // for each item, find left most item that is smaller or equal to it
        // an observation: a number is larger than previous is useless
        int n = A.size();
        stack<int> s;
        for(int i = 0; i < n; ++i) {
            if(s.empty() || A[i] < A[s.top()])
                s.push(i);
        }
        int mx = 0;
        for(int i = n - 1; i >= 0; --i) {
            while(!s.empty() && A[i] >= A[s.top()]) {
                mx = max(mx, i - s.top());
                s.pop();
            }
        }
        return mx;
    }
};

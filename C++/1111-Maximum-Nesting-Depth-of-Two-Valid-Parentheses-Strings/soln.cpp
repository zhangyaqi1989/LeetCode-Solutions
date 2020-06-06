
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int A = 0, B = 0, cntA = 0, cntB = 0;
        int n = seq.length();
        vector<int> ans(n, 0);
        int i = 0;
        for(char ch : seq) {
            if (ch == '(') {
                if (A <= B) {
                    cntA += 1;
                    A = max(A, cntA);
                    ++i;
                } else {
                    cntB += 1;
                    B = max(B, cntB);
                    ans[i++] = 1;
                }
            } else {
                if (cntA >= cntB) {
                    --cntA;
                    ++i;
                } else {
                    --cntB;
                    ans[i++] = 1;
                }
            }
        }
        return ans;
    }
};

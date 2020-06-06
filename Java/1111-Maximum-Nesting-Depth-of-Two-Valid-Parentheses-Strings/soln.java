class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int n = seq.length();
        int [] ans = new int [n];
        int A = 0, B = 0, cntA = 0, cntB = 0;
        for(int i = 0; i < n; ++i) {
            char ch = seq.charAt(i);
            if (ch == '(') {
                if (A <= B) {
                    cntA += 1;
                    A = Math.max(A, cntA);
                } else {
                    cntB += 1;
                    B = Math.max(B, cntB);
                    ans[i] = 1;
                }
            } else {
                if (cntA >= cntB) {
                    --cntA;
                } else {
                    --cntB;
                    ans[i] = 1;
                }
            }
        }
        return ans;
    }
}

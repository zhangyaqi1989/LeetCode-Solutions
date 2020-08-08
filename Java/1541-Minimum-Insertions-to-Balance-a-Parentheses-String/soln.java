class Solution {
    public int minInsertions(String s) {
        int nlefts = 0;
        int n = s.length();
        int ans = 0;
        for(int i = 0, j = 0; i < n; i = j) {
            j = i;
            while(j < n && s.charAt(j) == s.charAt(i)) ++j;
            int cnt = j - i;
            if(s.charAt(i) == '(') {
                nlefts += cnt;
            } else {
                int nrights = (cnt + 1) / 2;
                if(cnt % 2 == 1) ++ans;
                if(nlefts < nrights) {
                    ans += nrights - nlefts;
                    nlefts = nrights;
                }
                nlefts -= nrights;
            }
        }
        return nlefts * 2 + ans;
    }
}

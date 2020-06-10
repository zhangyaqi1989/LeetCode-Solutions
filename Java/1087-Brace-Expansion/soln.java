class Solution {
    public String[] permute(String S) {
        List<String> ans = new ArrayList<>();
        ans.add("");
        int i = 0, n = S.length();
        while (i < n) {
            int j = S.indexOf('{', i);
            List<String> temp = new ArrayList<>();
            if (j == -1) {
                String add = S.substring(i);
                for(String item : ans) {
                    temp.add(item + add);
                }
                i = n;
            } else {
                String add = S.substring(i, j);
                int jj = S.indexOf('}', j + 1);
                String str = S.substring(j + 1, jj);
                String [] tokens = str.split(",");
                for(String item : ans) {
                    for(String token : tokens) {
                        temp.add(item + add + token);
                    }
                } 
                i = jj + 1;
            }
            ans = temp;
        }
        Collections.sort(ans);
        int m = ans.size();
        String [] res = new String[m];
        for(int j = 0; j < m; ++j)
            res[j] = ans.get(j);
        return res;
    }
}

class Solution {
    public String rankTeams(String[] votes) {
        final int M = votes[0].length();
        int [][] ranks = new int[26][M + 1];
        for(int i = 0; i < 26; ++i) Arrays.fill(ranks[i], 0);
        for(String vote : votes) {
            for(int idx = 0; idx < M; ++idx) {
                --ranks[vote.charAt(idx) - 'A'][idx];
            }
        }
        for(char ch : votes[0].toCharArray()) {
            ranks[ch - 'A'][M] = (int) ch;
        }
        Arrays.sort(ranks, new Comparator<int[]>() {
            @Override
            public int compare(int [] a, int [] b) {
                int n = a.length;
                for(int i = 0; i < n; ++i) {
                    if(a[i] != b[i]) return a[i] - b[i];
                }
                return -1;
            }
        });
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < 26; ++i) {
            if(ranks[i][M] != 0) sb.append((char) ranks[i][M]);
        }
        return sb.toString();
    }
}
